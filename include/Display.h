#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class Display {
public:
	Display(const std::string title, const int width, const int height, const bool fullscreen);
	std::string getErrorLog();
	bool checkExtensions(const std::string extensions);
	void update();
	bool isRunning();
	void quit();
	~Display();
private:
	bool running;
	SDL_Window *window;
	SDL_GLContext *context;
	std::string errorLog;
	void clear(void);
	void swap(void);
};

#endif
