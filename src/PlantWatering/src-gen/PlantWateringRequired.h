
#ifndef PLANTWATERINGREQUIRED_H_
#define PLANTWATERINGREQUIRED_H_

#include "..\src\sc_types.h"
#include "PlantWatering.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
	- plantWatering_setTimer and
	- plantWatering_unsetTimer
are defined.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- plantWateringIface_getMoistureSensorData
	- plantWateringIface_getRainSensorData
	- plantWateringIface_turnOnValve
	- plantWateringIface_turnOffValve
	- plantWateringIface_clearLCD
	- plantWateringIface_displayMoistureLCD
	- plantWateringIface_displayRainingLCD
	- plantWateringIface_displayModeLCD
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern sc_integer plantWateringIface_getMoistureSensorData(const PlantWatering* handle, const sc_string pin);
extern sc_boolean plantWateringIface_getRainSensorData(const PlantWatering* handle);
extern void plantWateringIface_turnOnValve(const PlantWatering* handle);
extern void plantWateringIface_turnOffValve(const PlantWatering* handle);
extern void plantWateringIface_clearLCD(const PlantWatering* handle);
extern void plantWateringIface_displayMoistureLCD(const PlantWatering* handle, const sc_integer moisture);
extern void plantWateringIface_displayRainingLCD(const PlantWatering* handle, const sc_boolean isRaining);
extern void plantWateringIface_displayModeLCD(const PlantWatering* handle, const sc_string mode);


/*!
 * This is a timed state machine that requires timer services
 */ 

/*! This function has to set up timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milliseconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset 
*/
extern void plantWatering_setTimer(PlantWatering* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);

/*! This function has to unset timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event that is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
extern void plantWatering_unsetTimer(PlantWatering* handle, const sc_eventid evid);



#ifdef __cplusplus
}
#endif 

#endif /* PLANTWATERINGREQUIRED_H_ */
