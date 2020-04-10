#include <dc/maple.h>
#include <dc/maple/controller.h>

/*
 *the Button function in Controller class 
 * is used in this manner
 * controller.Button(START);
 */

enum Buttons
{
	A = CONT_A,
	B = CONT_B, 
	X = CONT_X,
	Y = CONT_Y,
	START = CONT_START,
};

class Controller
{
private:
	cont_state_t *state;
	
public:
	Controller();
	~Controller();
	
	void UpdateControllerState();
	
	bool Button(Buttons button) const;
	
	float JoystickX() const;
	float JoystickY() const;
};