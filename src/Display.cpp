#include "Display.h"

/* creates an OpenGL enabled window with GLEW and SDL2 */
Display::Display(const std::string title, const int width, const int height, const bool fullscreen) {
	running=true;
	/* initializing SDL2 */
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
		/* defining attributes; using OpenGL version 3.0 */
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		/* creating the window and context */
		if(fullscreen)
			window=SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		else
			window=SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		/* error checking */
		if (window != NULL){
			glewExperimental=GL_TRUE;
			context=(SDL_GLContext *)SDL_GL_CreateContext(window);
			if (context != NULL){
				if (glewInit() != GLEW_OK)
					errorLog+="GLEW could not be initialized!";
				glGetError();
			}else
				errorLog+="OpenGL context could not be created! "+std::string(SDL_GetError());
		}else
			errorLog+="Window could not be created! "+std::string(SDL_GetError());
	}else
		errorLog+="SDL2 could not be initialized! "+std::string(SDL_GetError());
}

/* retrieving the error log */
std::string Display::getErrorLog(){
	return errorLog;
}

/* checking if extensions were loaded properly using GLEW */
bool Display::checkExtensions(const std::string extensions) {
	return glewIsSupported(extensions.c_str());
}

/* updating the screen */
void Display::update(){
	clear();
	swap();
	if(!isRunning())
		delete this;
}

/* clearing the back buffer for drawing */
void Display::clear(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/* swapping the buffer after drawing */
void Display::swap(void) {
	SDL_GL_SwapWindow(window);
}

bool Display::isRunning(){
	return running;
}

void Display::quit(void){
	running=false;
}

/* cleanig up */
Display::~Display() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}