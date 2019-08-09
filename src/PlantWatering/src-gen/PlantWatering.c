
#include "PlantWatering.h"
#include "..\src\sc_types.h"
#include "PlantWateringRequired.h"

#include <string.h>
/*! \file Implementation of the state machine 'PlantWatering'
*/

/* prototypes of all internal functions */
static sc_boolean check_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0_tr0_tr0(const PlantWatering* handle);
static sc_boolean check_Main_region_Timer_interrupt_Main_region__choice_0_tr0_tr0(const PlantWatering* handle);
static sc_boolean check_Main_region__choice_0_tr0_tr0(const PlantWatering* handle);
static sc_boolean check_Main_region__choice_0_tr1_tr1(const PlantWatering* handle);
static void effect_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0_tr0(PlantWatering* handle);
static void effect_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0_tr1(PlantWatering* handle);
static void effect_Main_region_Timer_interrupt_Main_region__choice_0_tr0(PlantWatering* handle);
static void effect_Main_region_Timer_interrupt_Main_region__choice_0_tr1(PlantWatering* handle);
static void effect_Main_region__choice_0_tr0(PlantWatering* handle);
static void effect_Main_region__choice_0_tr1(PlantWatering* handle);
static void effect_Main_region__choice_0_tr2(PlantWatering* handle);
static void enact_Main_region_Main(PlantWatering* handle);
static void enact_Main_region_Main_Main_region_ValveOff(PlantWatering* handle);
static void enact_Main_region_Main_Main_region_ValveOn(PlantWatering* handle);
static void enact_Main_region_Timer_interrupt_Main_region_CheckSensors(PlantWatering* handle);
static void enact_Main_region_Timer_interrupt_Main_region_Display(PlantWatering* handle);
static void exact_Main_region_Main(PlantWatering* handle);
static void enseq_Main_region_Main_default(PlantWatering* handle);
static void enseq_Main_region_Main_Main_region_ValveOff_default(PlantWatering* handle);
static void enseq_Main_region_Main_Main_region_ValveOn_default(PlantWatering* handle);
static void enseq_Main_region_Main_Main_region_Idle_default(PlantWatering* handle);
static void enseq_Main_region_Main_Main_region_Manual_Control_default(PlantWatering* handle);
static void enseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn_default(PlantWatering* handle);
static void enseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff_default(PlantWatering* handle);
static void enseq_Main_region_Timer_interrupt_default(PlantWatering* handle);
static void enseq_Main_region_Timer_interrupt_Main_region_CheckSensors_default(PlantWatering* handle);
static void enseq_Main_region_Timer_interrupt_Main_region_Display_default(PlantWatering* handle);
static void enseq_Main_region_default(PlantWatering* handle);
static void enseq_Main_region_Main_Main_region_default(PlantWatering* handle);
static void enseq_Main_region_Main_Main_region_Manual_Control_Main_region_default(PlantWatering* handle);
static void enseq_Main_region_Timer_interrupt_Main_region_default(PlantWatering* handle);
static void exseq_Main_region_Main(PlantWatering* handle);
static void exseq_Main_region_Main_Main_region_ValveOff(PlantWatering* handle);
static void exseq_Main_region_Main_Main_region_ValveOn(PlantWatering* handle);
static void exseq_Main_region_Main_Main_region_Idle(PlantWatering* handle);
static void exseq_Main_region_Main_Main_region_Manual_Control(PlantWatering* handle);
static void exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn(PlantWatering* handle);
static void exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff(PlantWatering* handle);
static void exseq_Main_region_Timer_interrupt(PlantWatering* handle);
static void exseq_Main_region_Timer_interrupt_Main_region_CheckSensors(PlantWatering* handle);
static void exseq_Main_region_Timer_interrupt_Main_region_Display(PlantWatering* handle);
static void exseq_Main_region(PlantWatering* handle);
static void exseq_Main_region_Main_Main_region(PlantWatering* handle);
static void exseq_Main_region_Main_Main_region_Manual_Control_Main_region(PlantWatering* handle);
static void exseq_Main_region_Timer_interrupt_Main_region(PlantWatering* handle);
static void react_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0(PlantWatering* handle);
static void react_Main_region_Timer_interrupt_Main_region__choice_0(PlantWatering* handle);
static void react_Main_region__choice_0(PlantWatering* handle);
static void react_Main_region__entry_Default(PlantWatering* handle);
static void react_Main_region_Main_Main_region__entry_Default(PlantWatering* handle);
static void react_Main_region_Main_Main_region_Manual_Control_Main_region__entry_Default(PlantWatering* handle);
static void react_Main_region_Timer_interrupt_Main_region__entry_Default(PlantWatering* handle);
static sc_boolean react(PlantWatering* handle);
static sc_boolean Main_region_Main_react(PlantWatering* handle, const sc_boolean try_transition);
static sc_boolean Main_region_Main_Main_region_ValveOff_react(PlantWatering* handle, const sc_boolean try_transition);
static sc_boolean Main_region_Main_Main_region_ValveOn_react(PlantWatering* handle, const sc_boolean try_transition);
static sc_boolean Main_region_Main_Main_region_Idle_react(PlantWatering* handle, const sc_boolean try_transition);
static sc_boolean Main_region_Main_Main_region_Manual_Control_react(PlantWatering* handle, const sc_boolean try_transition);
static sc_boolean Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn_react(PlantWatering* handle, const sc_boolean try_transition);
static sc_boolean Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff_react(PlantWatering* handle, const sc_boolean try_transition);
static sc_boolean Main_region_Timer_interrupt_react(PlantWatering* handle, const sc_boolean try_transition);
static sc_boolean Main_region_Timer_interrupt_Main_region_CheckSensors_react(PlantWatering* handle, const sc_boolean try_transition);
static sc_boolean Main_region_Timer_interrupt_Main_region_Display_react(PlantWatering* handle, const sc_boolean try_transition);
static void clearInEvents(PlantWatering* handle);
static void clearOutEvents(PlantWatering* handle);

const sc_string PLANTWATERING_PLANTWATERINGIFACE_MOISTURESENSORPIN = "A0";

void plantWatering_init(PlantWatering* handle)
{
	sc_integer i;
	
	for (i = 0; i < PLANTWATERING_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = PlantWatering_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;
	
	clearInEvents(handle);
	clearOutEvents(handle);
	
	/* Default init sequence for statechart PlantWatering */
	handle->iface.isValveOn = bool_false;
	handle->iface.moisture = 0;
	handle->iface.isRaining = bool_false;
	handle->iface.mode = "automatic";
}

void plantWatering_enter(PlantWatering* handle)
{
	/* Default enter sequence for statechart PlantWatering */
	enseq_Main_region_default(handle);
}

void plantWatering_runCycle(PlantWatering* handle)
{
	clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PLANTWATERING_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case PlantWatering_Main_region_Main_Main_region_ValveOff:
		{
			Main_region_Main_Main_region_ValveOff_react(handle, bool_true);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_ValveOn:
		{
			Main_region_Main_Main_region_ValveOn_react(handle, bool_true);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Idle:
		{
			Main_region_Main_Main_region_Idle_react(handle, bool_true);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn:
		{
			Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn_react(handle, bool_true);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff:
		{
			Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff_react(handle, bool_true);
			break;
		}
		case PlantWatering_Main_region_Timer_interrupt_Main_region_CheckSensors:
		{
			Main_region_Timer_interrupt_Main_region_CheckSensors_react(handle, bool_true);
			break;
		}
		case PlantWatering_Main_region_Timer_interrupt_Main_region_Display:
		{
			Main_region_Timer_interrupt_Main_region_Display_react(handle, bool_true);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void plantWatering_exit(PlantWatering* handle)
{
	/* Default exit sequence for statechart PlantWatering */
	exseq_Main_region(handle);
}

sc_boolean plantWatering_isActive(const PlantWatering* handle)
{
	sc_boolean result = bool_false;
	sc_integer i;
	
	for(i = 0; i < PLANTWATERING_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != PlantWatering_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean plantWatering_isFinal(const PlantWatering* handle)
{
   return bool_false;
}

void plantWatering_raiseTimeEvent(PlantWatering* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + (unsigned)sizeof(PlantWateringTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean plantWatering_isStateActive(const PlantWatering* handle, PlantWateringStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case PlantWatering_Main_region_Main :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_MAIN] >= PlantWatering_Main_region_Main
				&& handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_MAIN] <= PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff);
			break;
		case PlantWatering_Main_region_Main_Main_region_ValveOff :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_VALVEOFF] == PlantWatering_Main_region_Main_Main_region_ValveOff
			);
			break;
		case PlantWatering_Main_region_Main_Main_region_ValveOn :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_VALVEON] == PlantWatering_Main_region_Main_Main_region_ValveOn
			);
			break;
		case PlantWatering_Main_region_Main_Main_region_Idle :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_IDLE] == PlantWatering_Main_region_Main_Main_region_Idle
			);
			break;
		case PlantWatering_Main_region_Main_Main_region_Manual_Control :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_MANUAL_CONTROL] >= PlantWatering_Main_region_Main_Main_region_Manual_Control
				&& handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_MANUAL_CONTROL] <= PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff);
			break;
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_MANUAL_CONTROL_MAIN_REGION_VALVEON] == PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn
			);
			break;
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_MAIN_MAIN_REGION_MANUAL_CONTROL_MAIN_REGION_VALVEOFF] == PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff
			);
			break;
		case PlantWatering_Main_region_Timer_interrupt :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_TIMER_INTERRUPT] >= PlantWatering_Main_region_Timer_interrupt
				&& handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_TIMER_INTERRUPT] <= PlantWatering_Main_region_Timer_interrupt_Main_region_Display);
			break;
		case PlantWatering_Main_region_Timer_interrupt_Main_region_CheckSensors :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_TIMER_INTERRUPT_MAIN_REGION_CHECKSENSORS] == PlantWatering_Main_region_Timer_interrupt_Main_region_CheckSensors
			);
			break;
		case PlantWatering_Main_region_Timer_interrupt_Main_region_Display :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PLANTWATERING_MAIN_REGION_TIMER_INTERRUPT_MAIN_REGION_DISPLAY] == PlantWatering_Main_region_Timer_interrupt_Main_region_Display
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clearInEvents(PlantWatering* handle)
{
	handle->iface.pressButtonB1_raised = bool_false;
	handle->iface.pressButtonB2_raised = bool_false;
	handle->timeEvents.plantWatering_Main_region_Main_tev0_raised = bool_false;
}

static void clearOutEvents(PlantWatering* handle)
{
}

void plantWateringIface_raise_pressButtonB1(PlantWatering* handle)
{
	handle->iface.pressButtonB1_raised = bool_true;
}
void plantWateringIface_raise_pressButtonB2(PlantWatering* handle)
{
	handle->iface.pressButtonB2_raised = bool_true;
}


const sc_string plantWateringIface_get_moistureSensorPin(const PlantWatering* handle)
{
	return PLANTWATERING_PLANTWATERINGIFACE_MOISTURESENSORPIN;
}
sc_boolean plantWateringIface_get_isValveOn(const PlantWatering* handle)
{
	return handle->iface.isValveOn;
}
void plantWateringIface_set_isValveOn(PlantWatering* handle, sc_boolean value)
{
	handle->iface.isValveOn = value;
}
sc_integer plantWateringIface_get_moisture(const PlantWatering* handle)
{
	return handle->iface.moisture;
}
void plantWateringIface_set_moisture(PlantWatering* handle, sc_integer value)
{
	handle->iface.moisture = value;
}
sc_boolean plantWateringIface_get_isRaining(const PlantWatering* handle)
{
	return handle->iface.isRaining;
}
void plantWateringIface_set_isRaining(PlantWatering* handle, sc_boolean value)
{
	handle->iface.isRaining = value;
}
sc_string plantWateringIface_get_mode(const PlantWatering* handle)
{
	return handle->iface.mode;
}
void plantWateringIface_set_mode(PlantWatering* handle, sc_string value)
{
	handle->iface.mode = value;
}

/* implementations of all internal functions */

static sc_boolean check_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0_tr0_tr0(const PlantWatering* handle)
{
	return (handle->iface.isValveOn) == (bool_true);
}

static sc_boolean check_Main_region_Timer_interrupt_Main_region__choice_0_tr0_tr0(const PlantWatering* handle)
{
	return (strcmp(handle->iface.mode, "manual") == 0)
	;
}

static sc_boolean check_Main_region__choice_0_tr0_tr0(const PlantWatering* handle)
{
	return ((handle->iface.isValveOn) == (bool_true)) && ((((handle->iface.isRaining) == (bool_true)) || ((handle->iface.moisture) >= (50))) == bool_true);
}

static sc_boolean check_Main_region__choice_0_tr1_tr1(const PlantWatering* handle)
{
	return (((handle->iface.isValveOn) == (bool_false)) && ((handle->iface.isRaining) == (bool_false))) && ((handle->iface.moisture) < (50));
}

static void effect_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0_tr0(PlantWatering* handle)
{
	enseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn_default(handle);
}

static void effect_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0_tr1(PlantWatering* handle)
{
	enseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff_default(handle);
}

static void effect_Main_region_Timer_interrupt_Main_region__choice_0_tr0(PlantWatering* handle)
{
	exseq_Main_region_Timer_interrupt(handle);
	enact_Main_region_Main(handle);
	enseq_Main_region_Main_Main_region_Manual_Control_default(handle);
}

static void effect_Main_region_Timer_interrupt_Main_region__choice_0_tr1(PlantWatering* handle)
{
	exseq_Main_region_Timer_interrupt(handle);
	react_Main_region__choice_0(handle);
}

static void effect_Main_region__choice_0_tr0(PlantWatering* handle)
{
	enact_Main_region_Main(handle);
	enseq_Main_region_Main_Main_region_ValveOff_default(handle);
}

static void effect_Main_region__choice_0_tr1(PlantWatering* handle)
{
	enact_Main_region_Main(handle);
	enseq_Main_region_Main_Main_region_ValveOn_default(handle);
}

static void effect_Main_region__choice_0_tr2(PlantWatering* handle)
{
	enact_Main_region_Main(handle);
	enseq_Main_region_Main_Main_region_Idle_default(handle);
}

/* Entry action for state 'Main'. */
static void enact_Main_region_Main(PlantWatering* handle)
{
	/* Entry action for state 'Main'. */
	plantWatering_setTimer(handle, (sc_eventid) &(handle->timeEvents.plantWatering_Main_region_Main_tev0_raised) , (5 * 1000), bool_true);
}

/* Entry action for state 'ValveOff'. */
static void enact_Main_region_Main_Main_region_ValveOff(PlantWatering* handle)
{
	/* Entry action for state 'ValveOff'. */
	plantWateringIface_turnOffValve(handle);
	handle->iface.isValveOn = bool_false;
}

/* Entry action for state 'ValveOn'. */
static void enact_Main_region_Main_Main_region_ValveOn(PlantWatering* handle)
{
	/* Entry action for state 'ValveOn'. */
	handle->iface.isValveOn = bool_true;
	plantWateringIface_turnOnValve(handle);
}

/* Entry action for state 'CheckSensors'. */
static void enact_Main_region_Timer_interrupt_Main_region_CheckSensors(PlantWatering* handle)
{
	/* Entry action for state 'CheckSensors'. */
	handle->iface.moisture = plantWateringIface_getMoistureSensorData(handle, PLANTWATERING_PLANTWATERINGIFACE_MOISTURESENSORPIN);
	handle->iface.isRaining = plantWateringIface_getRainSensorData(handle);
}

/* Entry action for state 'Display'. */
static void enact_Main_region_Timer_interrupt_Main_region_Display(PlantWatering* handle)
{
	/* Entry action for state 'Display'. */
	plantWateringIface_clearLCD(handle);
	plantWateringIface_displayMoistureLCD(handle, handle->iface.moisture);
	plantWateringIface_displayModeLCD(handle, handle->iface.mode);
}

/* Exit action for state 'Main'. */
static void exact_Main_region_Main(PlantWatering* handle)
{
	/* Exit action for state 'Main'. */
	plantWatering_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.plantWatering_Main_region_Main_tev0_raised) );		
}

/* 'default' enter sequence for state Main */
static void enseq_Main_region_Main_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state Main */
	enact_Main_region_Main(handle);
	enseq_Main_region_Main_Main_region_default(handle);
}

/* 'default' enter sequence for state ValveOff */
static void enseq_Main_region_Main_Main_region_ValveOff_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state ValveOff */
	enact_Main_region_Main_Main_region_ValveOff(handle);
	handle->stateConfVector[0] = PlantWatering_Main_region_Main_Main_region_ValveOff;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ValveOn */
static void enseq_Main_region_Main_Main_region_ValveOn_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state ValveOn */
	enact_Main_region_Main_Main_region_ValveOn(handle);
	handle->stateConfVector[0] = PlantWatering_Main_region_Main_Main_region_ValveOn;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Idle */
static void enseq_Main_region_Main_Main_region_Idle_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state Idle */
	handle->stateConfVector[0] = PlantWatering_Main_region_Main_Main_region_Idle;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Manual Control */
static void enseq_Main_region_Main_Main_region_Manual_Control_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state Manual Control */
	enseq_Main_region_Main_Main_region_Manual_Control_Main_region_default(handle);
}

/* 'default' enter sequence for state ValveOn */
static void enseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state ValveOn */
	handle->stateConfVector[0] = PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ValveOff */
static void enseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state ValveOff */
	handle->stateConfVector[0] = PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Timer interrupt */
static void enseq_Main_region_Timer_interrupt_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state Timer interrupt */
	enseq_Main_region_Timer_interrupt_Main_region_default(handle);
}

/* 'default' enter sequence for state CheckSensors */
static void enseq_Main_region_Timer_interrupt_Main_region_CheckSensors_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state CheckSensors */
	enact_Main_region_Timer_interrupt_Main_region_CheckSensors(handle);
	handle->stateConfVector[0] = PlantWatering_Main_region_Timer_interrupt_Main_region_CheckSensors;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Display */
static void enseq_Main_region_Timer_interrupt_Main_region_Display_default(PlantWatering* handle)
{
	/* 'default' enter sequence for state Display */
	enact_Main_region_Timer_interrupt_Main_region_Display(handle);
	handle->stateConfVector[0] = PlantWatering_Main_region_Timer_interrupt_Main_region_Display;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region Main region */
static void enseq_Main_region_default(PlantWatering* handle)
{
	/* 'default' enter sequence for region Main region */
	react_Main_region__entry_Default(handle);
}

/* 'default' enter sequence for region Main region */
static void enseq_Main_region_Main_Main_region_default(PlantWatering* handle)
{
	/* 'default' enter sequence for region Main region */
	react_Main_region_Main_Main_region__entry_Default(handle);
}

/* 'default' enter sequence for region Main region */
static void enseq_Main_region_Main_Main_region_Manual_Control_Main_region_default(PlantWatering* handle)
{
	/* 'default' enter sequence for region Main region */
	react_Main_region_Main_Main_region_Manual_Control_Main_region__entry_Default(handle);
}

/* 'default' enter sequence for region Main region */
static void enseq_Main_region_Timer_interrupt_Main_region_default(PlantWatering* handle)
{
	/* 'default' enter sequence for region Main region */
	react_Main_region_Timer_interrupt_Main_region__entry_Default(handle);
}

/* Default exit sequence for state Main */
static void exseq_Main_region_Main(PlantWatering* handle)
{
	/* Default exit sequence for state Main */
	exseq_Main_region_Main_Main_region(handle);
	exact_Main_region_Main(handle);
}

/* Default exit sequence for state ValveOff */
static void exseq_Main_region_Main_Main_region_ValveOff(PlantWatering* handle)
{
	/* Default exit sequence for state ValveOff */
	handle->stateConfVector[0] = PlantWatering_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ValveOn */
static void exseq_Main_region_Main_Main_region_ValveOn(PlantWatering* handle)
{
	/* Default exit sequence for state ValveOn */
	handle->stateConfVector[0] = PlantWatering_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Idle */
static void exseq_Main_region_Main_Main_region_Idle(PlantWatering* handle)
{
	/* Default exit sequence for state Idle */
	handle->stateConfVector[0] = PlantWatering_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Manual Control */
static void exseq_Main_region_Main_Main_region_Manual_Control(PlantWatering* handle)
{
	/* Default exit sequence for state Manual Control */
	exseq_Main_region_Main_Main_region_Manual_Control_Main_region(handle);
}

/* Default exit sequence for state ValveOn */
static void exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn(PlantWatering* handle)
{
	/* Default exit sequence for state ValveOn */
	handle->stateConfVector[0] = PlantWatering_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ValveOff */
static void exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff(PlantWatering* handle)
{
	/* Default exit sequence for state ValveOff */
	handle->stateConfVector[0] = PlantWatering_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Timer interrupt */
static void exseq_Main_region_Timer_interrupt(PlantWatering* handle)
{
	/* Default exit sequence for state Timer interrupt */
	exseq_Main_region_Timer_interrupt_Main_region(handle);
}

/* Default exit sequence for state CheckSensors */
static void exseq_Main_region_Timer_interrupt_Main_region_CheckSensors(PlantWatering* handle)
{
	/* Default exit sequence for state CheckSensors */
	handle->stateConfVector[0] = PlantWatering_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Display */
static void exseq_Main_region_Timer_interrupt_Main_region_Display(PlantWatering* handle)
{
	/* Default exit sequence for state Display */
	handle->stateConfVector[0] = PlantWatering_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region Main region */
static void exseq_Main_region(PlantWatering* handle)
{
	/* Default exit sequence for region Main region */
	/* Handle exit of all possible states (of PlantWatering.Main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case PlantWatering_Main_region_Main_Main_region_ValveOff :
		{
			exseq_Main_region_Main_Main_region_ValveOff(handle);
			exact_Main_region_Main(handle);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_ValveOn :
		{
			exseq_Main_region_Main_Main_region_ValveOn(handle);
			exact_Main_region_Main(handle);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Idle :
		{
			exseq_Main_region_Main_Main_region_Idle(handle);
			exact_Main_region_Main(handle);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn :
		{
			exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn(handle);
			exact_Main_region_Main(handle);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff :
		{
			exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff(handle);
			exact_Main_region_Main(handle);
			break;
		}
		case PlantWatering_Main_region_Timer_interrupt_Main_region_CheckSensors :
		{
			exseq_Main_region_Timer_interrupt_Main_region_CheckSensors(handle);
			break;
		}
		case PlantWatering_Main_region_Timer_interrupt_Main_region_Display :
		{
			exseq_Main_region_Timer_interrupt_Main_region_Display(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Main region */
static void exseq_Main_region_Main_Main_region(PlantWatering* handle)
{
	/* Default exit sequence for region Main region */
	/* Handle exit of all possible states (of PlantWatering.Main_region.Main.Main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case PlantWatering_Main_region_Main_Main_region_ValveOff :
		{
			exseq_Main_region_Main_Main_region_ValveOff(handle);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_ValveOn :
		{
			exseq_Main_region_Main_Main_region_ValveOn(handle);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Idle :
		{
			exseq_Main_region_Main_Main_region_Idle(handle);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn :
		{
			exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn(handle);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff :
		{
			exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Main region */
static void exseq_Main_region_Main_Main_region_Manual_Control_Main_region(PlantWatering* handle)
{
	/* Default exit sequence for region Main region */
	/* Handle exit of all possible states (of PlantWatering.Main_region.Main.Main_region.Manual_Control.Main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn :
		{
			exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn(handle);
			break;
		}
		case PlantWatering_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff :
		{
			exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Main region */
static void exseq_Main_region_Timer_interrupt_Main_region(PlantWatering* handle)
{
	/* Default exit sequence for region Main region */
	/* Handle exit of all possible states (of PlantWatering.Main_region.Timer_interrupt.Main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case PlantWatering_Main_region_Timer_interrupt_Main_region_CheckSensors :
		{
			exseq_Main_region_Timer_interrupt_Main_region_CheckSensors(handle);
			break;
		}
		case PlantWatering_Main_region_Timer_interrupt_Main_region_Display :
		{
			exseq_Main_region_Timer_interrupt_Main_region_Display(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state null. */
static void react_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0(PlantWatering* handle)
{
	/* The reactions of state null. */
	if (check_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0_tr0_tr0(handle) == bool_true)
	{ 
		effect_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0_tr0(handle);
	}  else
	{
		effect_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0_tr1(handle);
	}
}

/* The reactions of state null. */
static void react_Main_region_Timer_interrupt_Main_region__choice_0(PlantWatering* handle)
{
	/* The reactions of state null. */
	if (check_Main_region_Timer_interrupt_Main_region__choice_0_tr0_tr0(handle) == bool_true)
	{ 
		effect_Main_region_Timer_interrupt_Main_region__choice_0_tr0(handle);
	}  else
	{
		effect_Main_region_Timer_interrupt_Main_region__choice_0_tr1(handle);
	}
}

/* The reactions of state null. */
static void react_Main_region__choice_0(PlantWatering* handle)
{
	/* The reactions of state null. */
	if (check_Main_region__choice_0_tr0_tr0(handle) == bool_true)
	{ 
		effect_Main_region__choice_0_tr0(handle);
	}  else
	{
		if (check_Main_region__choice_0_tr1_tr1(handle) == bool_true)
		{ 
			effect_Main_region__choice_0_tr1(handle);
		}  else
		{
			effect_Main_region__choice_0_tr2(handle);
		}
	}
}

/* Default react sequence for initial entry  */
static void react_Main_region__entry_Default(PlantWatering* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Main_region_Main_default(handle);
}

/* Default react sequence for initial entry  */
static void react_Main_region_Main_Main_region__entry_Default(PlantWatering* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Main_region_Main_Main_region_Idle_default(handle);
}

/* Default react sequence for initial entry  */
static void react_Main_region_Main_Main_region_Manual_Control_Main_region__entry_Default(PlantWatering* handle)
{
	/* Default react sequence for initial entry  */
	react_Main_region_Main_Main_region_Manual_Control_Main_region__choice_0(handle);
}

/* Default react sequence for initial entry  */
static void react_Main_region_Timer_interrupt_Main_region__entry_Default(PlantWatering* handle)
{
	/* Default react sequence for initial entry  */
	enseq_Main_region_Timer_interrupt_Main_region_CheckSensors_default(handle);
}

static sc_boolean react(PlantWatering* handle) {
	/* State machine reactions. */
	return bool_false;
}

static sc_boolean Main_region_Main_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state Main. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((react(handle)) == (bool_false))
		{ 
			if (handle->timeEvents.plantWatering_Main_region_Main_tev0_raised == bool_true)
			{ 
				exseq_Main_region_Main(handle);
				enseq_Main_region_Timer_interrupt_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean Main_region_Main_Main_region_ValveOff_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state ValveOff. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((Main_region_Main_react(handle, try_transition)) == (bool_false))
		{ 
			exseq_Main_region_Main_Main_region_ValveOff(handle);
			enseq_Main_region_Main_Main_region_Idle_default(handle);
		} 
	} 
	return did_transition;
}

static sc_boolean Main_region_Main_Main_region_ValveOn_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state ValveOn. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((Main_region_Main_react(handle, try_transition)) == (bool_false))
		{ 
			exseq_Main_region_Main_Main_region_ValveOn(handle);
			enseq_Main_region_Main_Main_region_Idle_default(handle);
		} 
	} 
	return did_transition;
}

static sc_boolean Main_region_Main_Main_region_Idle_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state Idle. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((Main_region_Main_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.pressButtonB1_raised == bool_true)
			{ 
				exseq_Main_region_Main_Main_region_Idle(handle);
				handle->iface.mode = "manual";
				plantWateringIface_displayModeLCD(handle, handle->iface.mode);
				enseq_Main_region_Main_Main_region_Manual_Control_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean Main_region_Main_Main_region_Manual_Control_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state Manual Control. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((Main_region_Main_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.pressButtonB1_raised == bool_true)
			{ 
				exseq_Main_region_Main_Main_region_Manual_Control(handle);
				handle->iface.mode = "automatic";
				plantWateringIface_displayModeLCD(handle, handle->iface.mode);
				enseq_Main_region_Main_Main_region_Idle_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state ValveOn. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((Main_region_Main_Main_region_Manual_Control_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.pressButtonB2_raised == bool_true)
			{ 
				exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn(handle);
				plantWateringIface_turnOffValve(handle);
				handle->iface.isValveOn = bool_false;
				enseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state ValveOff. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((Main_region_Main_Main_region_Manual_Control_react(handle, try_transition)) == (bool_false))
		{ 
			if (handle->iface.pressButtonB2_raised == bool_true)
			{ 
				exseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOff(handle);
				plantWateringIface_turnOnValve(handle);
				handle->iface.isValveOn = bool_true;
				enseq_Main_region_Main_Main_region_Manual_Control_Main_region_ValveOn_default(handle);
			}  else
			{
				did_transition = bool_false;
			}
		} 
	} 
	return did_transition;
}

static sc_boolean Main_region_Timer_interrupt_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state Timer interrupt. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((react(handle)) == (bool_false))
		{ 
			did_transition = bool_false;
		} 
	} 
	return did_transition;
}

static sc_boolean Main_region_Timer_interrupt_Main_region_CheckSensors_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state CheckSensors. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((Main_region_Timer_interrupt_react(handle, try_transition)) == (bool_false))
		{ 
			exseq_Main_region_Timer_interrupt_Main_region_CheckSensors(handle);
			enseq_Main_region_Timer_interrupt_Main_region_Display_default(handle);
		} 
	} 
	return did_transition;
}

static sc_boolean Main_region_Timer_interrupt_Main_region_Display_react(PlantWatering* handle, const sc_boolean try_transition) {
	/* The reactions of state Display. */
	sc_boolean did_transition = try_transition;
	if (try_transition == bool_true)
	{ 
		if ((Main_region_Timer_interrupt_react(handle, try_transition)) == (bool_false))
		{ 
			exseq_Main_region_Timer_interrupt_Main_region_Display(handle);
			react_Main_region_Timer_interrupt_Main_region__choice_0(handle);
		} 
	} 
	return did_transition;
}


