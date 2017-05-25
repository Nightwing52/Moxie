#ifndef INPUT_H
#define INPUT_H

#include <array>
#include <cstring> //for using memcpy
#include <SDL2/SDL.h>
#include <cstdio>
#include "Display.h"
#include "Constants.h"
#include "Generic.h"

class Input {
public:
	Input(bool showCursor);
	void update(void);
	void setDefaultCloseOperation(Key key, Display *window);
	bool keyPressed(Key key);
	bool keyReleased(Key key);
	bool keyHeld(Key key);
	bool buttonPressed(Button mouseButton);
	int getXCoordinate(void);
	int getYCoordinate(void);
	Point getPoint(void);
	~Input(void);
private:
	Display *window; //for closing windows when the Key set under "setDefaultCloseOperation" has been pressed
	Key trigger; //closes the window
	/* keyboard states */
	const Uint8 *currentKeyboard;
	Uint8 *lastKeyboard;
	int xCoordinate;
	int yCoordinate;
};
#endif
