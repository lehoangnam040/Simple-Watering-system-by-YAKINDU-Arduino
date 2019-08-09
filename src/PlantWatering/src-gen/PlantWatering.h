
#ifndef PLANTWATERING_H_
#define PLANTWATERING_H_

#include "..\src\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'PlantWatering'.
*/

/*! Define number of states in the state enum */

#define PLANTWATERING_STATE_COUNT 10

/*! Define dimension of the state configuration vector for orthogonal states. */
#define PLANTWATERING_MAX_ORTHOGONAL_STATES 1

/*! Define maximum number of time events that can be active at once */
#define PLANTWATERING_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_PLANTWATERING_MAIN_REGION_MAIN 0
#define SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_VALVEOFF 0
#define SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_VALVEON 0
#define SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_IDLE 0
#define SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_MANUAL_CONTROL 0
#define SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_MANUAL_CONTROL_MAIN_REGION_VALVEON 0
#define SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_MANUAL_CONTROL_MAIN_REGION_VALVEOFF 0
#define SCVI_PLANTWATERING_MAIN_REGION_TIMER_INTERRUPT 0
#define SCVI_PLANTWATERING_MAIN_REGION_TIMER_INTERRUPT_MAIN_REGION_CHECKSENSORS 0
#define SCVI_PLANTWATERING_MAIN_REGION_TIMER_INTERRUPT_MAIN_REGION_DISPLAY 0

/*! Enumeration of all states */ 
typedef enum
{
	PlantWatering_last_state,
	PlantWatering_Main_region_Main,
	PlantWatering_Main_region_Main_Main_region_ValveOff,
	PlantWatering_Main_region_Main_Main_region_ValveOn,
	PlantWatering_Main_region_Main_Main_region_Idle,
	PlantWatering_Main_region_Main_Main_region_Manual_Control,
	PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn,
	PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff,
	PlantWatering_Main_region_Timer_interrupt,
	PlantWatering_Main_region_Timer_interrupt_Main_region_CheckSensors,
	PlantWatering_Main_region_Timer_interrupt_Main_region_Display
} PlantWateringStates;

/*! Type definition of the data structure for the PlantWateringIface interface scope. */
typedef struct
{
	sc_boolean isValveOn;
	sc_integer moisture;
	sc_boolean isRaining;
	sc_string mode;
	sc_boolean pressButtonB1_raised;
	sc_boolean pressButtonB2_raised;
} PlantWateringIface;


/* Declaration of constants for scope PlantWateringIface. */
extern const sc_string PLANTWATERING_PLANTWATERINGIFACE_MOISTURESENSORPIN;


/*! Type definition of the data structure for the PlantWateringTimeEvents interface scope. */
typedef struct
{
	sc_boolean plantWatering_Main_region_Main_tev0_raised;
} PlantWateringTimeEvents;




/*! 
 * Type definition of the data structure for the PlantWatering state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	PlantWateringStates stateConfVector[PLANTWATERING_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	PlantWateringIface iface;
	PlantWateringTimeEvents timeEvents;
} PlantWatering;



/*! Initializes the PlantWatering state machine data structures. Must be called before first usage.*/
extern void plantWatering_init(PlantWatering* handle);

/*! Activates the state machine */
extern void plantWatering_enter(PlantWatering* handle);

/*! Deactivates the state machine */
extern void plantWatering_exit(PlantWatering* handle);

/*! Performs a 'run to completion' step. */
extern void plantWatering_runCycle(PlantWatering* handle);

/*! Raises a time event. */
extern void plantWatering_raiseTimeEvent(PlantWatering* handle, sc_eventid evid);

/*! Gets the value of the variable 'moistureSensorPin' that is defined in the default interface scope. */ 
extern const sc_string plantWateringIface_get_moistureSensorPin(const PlantWatering* handle);
/*! Gets the value of the variable 'isValveOn' that is defined in the default interface scope. */ 
extern sc_boolean plantWateringIface_get_isValveOn(const PlantWatering* handle);
/*! Sets the value of the variable 'isValveOn' that is defined in the default interface scope. */ 
extern void plantWateringIface_set_isValveOn(PlantWatering* handle, sc_boolean value);
/*! Gets the value of the variable 'moisture' that is defined in the default interface scope. */ 
extern sc_integer plantWateringIface_get_moisture(const PlantWatering* handle);
/*! Sets the value of the variable 'moisture' that is defined in the default interface scope. */ 
extern void plantWateringIface_set_moisture(PlantWatering* handle, sc_integer value);
/*! Gets the value of the variable 'isRaining' that is defined in the default interface scope. */ 
extern sc_boolean plantWateringIface_get_isRaining(const PlantWatering* handle);
/*! Sets the value of the variable 'isRaining' that is defined in the default interface scope. */ 
extern void plantWateringIface_set_isRaining(PlantWatering* handle, sc_boolean value);
/*! Gets the value of the variable 'mode' that is defined in the default interface scope. */ 
extern sc_string plantWateringIface_get_mode(const PlantWatering* handle);
/*! Sets the value of the variable 'mode' that is defined in the default interface scope. */ 
extern void plantWateringIface_set_mode(PlantWatering* handle, sc_string value);
/*! Raises the in event 'pressButtonB1' that is defined in the default interface scope. */ 
extern void plantWateringIface_raise_pressButtonB1(PlantWatering* handle);

/*! Raises the in event 'pressButtonB2' that is defined in the default interface scope. */ 
extern void plantWateringIface_raise_pressButtonB2(PlantWatering* handle);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean plantWatering_isActive(const PlantWatering* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean plantWatering_isFinal(const PlantWatering* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean plantWatering_isStateActive(const PlantWatering* handle, PlantWateringStates state);


#ifdef __cplusplus
}
#endif 

#endif /* PLANTWATERING_H_ */
