#include "Input.h"

/* setting up keyboard input */
Input::Input(bool showCursor) {
	if(showCursor)
		SDL_ShowCursor(SDL_ENABLE);
	else
		SDL_ShowCursor(SDL_DISABLE);
	SDL_PumpEvents();
	int length;
	currentKeyboard=SDL_GetKeyboardState(&length);
	lastKeyboard=new Uint8[length];
}

/* updating the keystate arrays */
bool Input::update(void) {
	/* storing last frame's array BEFORE updating */
	std::memcpy(lastKeyboard, currentKeyboard, sizeof(currentKeyboard));
	SDL_PumpEvents();

	mouseState=SDL_GetMouseState(&xCoordinate, &yCoordinate);

	/* do we close? */
	if(keyPressed(trigger))
		return true;
    bool quit=false;
	SDL_Event *e=new SDL_Event();
	while(SDL_PollEvent(e) != 0)
		if(e->type == SDL_QUIT)
			quit=true;
	delete e;
	return quit;
}

void Input::setDefaultCloseOperation(Key key, Display *window){
	this->window=window;
	trigger=key;
}

/* testing if the key was pressed */
bool Input::keyPressed(Key key) {
	return(!lastKeyboard[key] && currentKeyboard[key]);
}

/* testing if the key was released */
bool Input::keyReleased(Key key) {
	return(lastKeyboard[key] && !currentKeyboard[key]);
}

/* testing if the key was held */
bool Input::keyHeld(Key key) {
	return(lastKeyboard[key] && currentKeyboard[key]);
}

/* testing if a button on the mouse is held; please pass in a SDL_BUTTON enum */
bool Input::buttonPressed(Button mouseButton) {
	return(mouseState & mouseButton);
}

/* getting the current 'x' coordinate */
int Input::getXCoordinate(void) {
	return xCoordinate;
}

/* getting the current 'y' coordinate */
int Input::getYCoordinate(void) {
	return yCoordinate;
}

Point Input::getPoint(void){
	return Point(getXCoordinate(), getYCoordinate());
}

/* cleaning up */
Input::~Input(void) {
	delete []lastKeyboard;
}
