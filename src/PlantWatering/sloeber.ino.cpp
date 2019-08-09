#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2019-08-07 22:34:14

#include "Arduino.h"
#include "Arduino.h"
#include <avr/sleep.h>
#include "string.h"
#include "LiquidCrystal.h"
#include "src-gen/PlantWatering.h"
#include "src-gen/PlantWateringRequired.h"
#include "scutil/sc_timer_service.h"

void plantWatering_setTimer(PlantWatering* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);
void plantWatering_unsetTimer(PlantWatering* handle, const sc_eventid evid) ;
sc_integer plantWateringIface_getMoistureSensorData(const PlantWatering* handle, const sc_string pin) ;
sc_boolean plantWateringIface_getRainSensorData(const PlantWatering* handle) ;
void plantWateringIface_turnOnValve(const PlantWatering* handle) ;
void plantWateringIface_turnOffValve(const PlantWatering* handle) ;
void plantWateringIface_clearLCD(const PlantWatering* handle) ;
void plantWateringIface_displayMoistureLCD(const PlantWatering* handle, const sc_integer moisture) ;
void plantWateringIface_displayRainingLCD(const PlantWatering* handle, const sc_boolean isRaining) ;
void plantWateringIface_displayModeLCD(const PlantWatering* handle, const sc_string mode) ;
void pressB1() ;
void pressB2() ;
void setup() ;
void loop() ;

#include "PlantWatering.ino"


#endif
