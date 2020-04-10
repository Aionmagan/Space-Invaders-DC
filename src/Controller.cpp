#ifndef __CONTROLLER
#define __CONTROLLER

#include "Controller.h"

/*constructor*/
Controller::Controller()
{
	UpdateControllerState();
}

/*destructor*/
Controller::~Controller()
{
	
}

void Controller::UpdateControllerState()
{
	state = (cont_state_t *)maple_dev_status(maple_enum_type(0, MAPLE_FUNC_CONTROLLER));
}

bool Controller::Button(Buttons button) const
{
	if(state != NULL)
	{
		return state->buttons & button;
	}
	return false;
}

float Controller::JoystickX() const
{
	if(state != NULL)
	{
		return state->joyx;
	}
	
	return 0;
}

float Controller::JoystickY() const
{
	if(state != NULL)
	{
		return state->joyy;
	}
	
	return 0;
}

#endif //__CONTROLLER