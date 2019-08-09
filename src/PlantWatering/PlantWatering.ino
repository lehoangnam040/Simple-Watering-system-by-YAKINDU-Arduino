#include "Arduino.h"
#include <avr/sleep.h>
#include "string.h"

#include "LiquidCrystal.h"

#include "src-gen/PlantWatering.h"
#include "src-gen/PlantWateringRequired.h"
#include "scutil/sc_timer_service.h"

#define MAX_TIMERS 20 //number of timers our timer service can use
#define CYCLE_PERIOD 10 //number of milliseconds that pass between each statechart cycle

static unsigned long cycle_count = 0L; //number of passed cycles
static unsigned long last_cycle_time = 0L; //timestamp of last cycle

static PlantWatering handle;

static sc_timer_service_t timer_service;

static sc_timer_t timers[MAX_TIMERS];

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const sc_integer motorPin = 8;


//! callback implementation for the setting up time events
void plantWatering_setTimer(PlantWatering* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	sc_timer_start(&timer_service, (void*) handle, evid, time_ms, periodic);
}

//! callback implementation for canceling time events.
void plantWatering_unsetTimer(PlantWatering* handle, const sc_eventid evid) {
	sc_timer_cancel(&timer_service, evid);
}

sc_integer plantWateringIface_getMoistureSensorData(const PlantWatering* handle, const sc_string pin) {
	sc_integer moistureSensorPin;
	if(strcmp("A0", pin) == 0)  {
		moistureSensorPin = A0;
	} else if (strcmp("A1", pin) == 0) {
		moistureSensorPin = A1;
	} else if (strcmp("A2", pin) == 0) {
		moistureSensorPin = A2;
	} else if (strcmp("A3", pin) == 0) {
		moistureSensorPin = A3;
	} else if (strcmp("A4", pin) == 0) {
		moistureSensorPin = A4;
	} else if (strcmp("A5", pin) == 0) {
		moistureSensorPin = A5;
	} else{
		return 0;
	}

	sc_integer moisture = analogRead(moistureSensorPin);
	sc_integer moisturePercent = map(moisture, 0, 1023, 0, 100);
	return moisturePercent;
}

sc_boolean plantWateringIface_getRainSensorData(const PlantWatering* handle) {
	int rain = digitalRead(9);
	return rain == HIGH;
}

void plantWateringIface_turnOnValve(const PlantWatering* handle) {
	digitalWrite(motorPin, HIGH);
}

void plantWateringIface_turnOffValve(const PlantWatering* handle) {
	digitalWrite(motorPin, LOW);
}

void plantWateringIface_clearLCD(const PlantWatering* handle) {
	lcd.clear();
}

void plantWateringIface_displayMoistureLCD(const PlantWatering* handle, const sc_integer moisture) {
	lcd.setCursor(0, 0);
	lcd.print(moisture);
	lcd.print("%");
}

void plantWateringIface_displayRainingLCD(const PlantWatering* handle, const sc_boolean isRaining) {
	lcd.setCursor(6, 0);
	lcd.print("Raining: ");
	lcd.print(isRaining);
}

void plantWateringIface_displayModeLCD(const PlantWatering* handle, const sc_string mode) {
	lcd.setCursor(0, 1);
	lcd.print("                ");
	lcd.setCursor(0, 1);
	lcd.print("Mode: ");
	lcd.print(mode);
}

void pressB1() {
	plantWateringIface_raise_pressButtonB1(&handle);
}

void pressB2() {
	plantWateringIface_raise_pressButtonB2(&handle);
}

void setup()
{
	Serial.begin(9600);
	lcd.begin(16, 2);
	lcd.print("Hello RICE 2019");
	pinMode(motorPin, OUTPUT);
	pinMode(3, INPUT_PULLUP);
	pinMode(2, INPUT_PULLUP);
	pinMode(9, INPUT);

	attachInterrupt(digitalPinToInterrupt(2), pressB1, RISING);
	attachInterrupt(digitalPinToInterrupt(3), pressB2, RISING);

	sc_timer_service_init(&timer_service,
			timers, MAX_TIMERS, (sc_raise_time_event_fp) &plantWatering_raiseTimeEvent);

	plantWatering_init(&handle); //initialize statechart
	plantWatering_enter(&handle); //enter the statechart
}

void loop()
{
	unsigned long current_millies = millis();
	if ( cycle_count == 0L || (current_millies >= last_cycle_time + CYCLE_PERIOD) ) {
		sc_timer_service_proceed(&timer_service, current_millies - last_cycle_time);
		plantWatering_runCycle(&handle);
		last_cycle_time = current_millies;
		cycle_count++;
	}
}
