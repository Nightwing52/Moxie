#include "Display.h"

/* creates an OpenGL enabled window with GLEW and SDL2 */
Display::Display(const string &title, const int width, const int height, const bool fullscreen) {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
                throw runtime_error(SDL_GetError());

        /* turning the fullscreen boolean into an SDL2 flag */
        Uint32 fullscreenFlag;
        if(fullscreen)
                fullscreenFlag=SDL_WINDOW_FULLSCREEN;
        else
            fullscreenFlag=SDL_WINDOW_RESIZABLE;

        gWin = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullscreenFlag | SDL_WINDOW_OPENGL);
        gCont = SDL_GL_CreateContext(gWin);

        if (gWin == NULL)
                throw runtime_error(SDL_GetError());
        else if (!gCont)
                throw runtime_error(SDL_GetError());

        if (glewInit() != GLEW_OK)
                throw runtime_error("Cannot initialize GLEW");

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

/* setting the FPS; usually to preserve power and CPU/GPU resources on lower end hardware */
void Display::SetFPS(const int newFPS){
        FPS=newFPS;
}

/* checking if extensions were loaded properly using GLEW */
bool Display::CheckExtensions(const string &glVersion, const string &extensions){
        if(glewIsSupported(glVersion.c_str()) && glewIsSupported(extensions.c_str()))
                return true;
        return false;
}

/* this method will be used to check if the window is active before each frame to save CPU/GPU time if it's running as a background proccess */
bool Display::IsActive(){
        while(SDL_PollEvent(event)){
                return(event->type==SDL_APP_DIDENTERFOREGROUND);
        }
}

/* limiting the FPS to save CPU/GPU time if the FPS limit is meet; can be used to prevent screen tearing and or power as well */
void Display::LimitFPS(Uint32 lastTime){
        Uint32 currentTime=SDL_GetTicks();

        if((currentTime-lastTime)<(1000/FPS))
                SDL_Delay((1000/FPS)-(currentTime-lastTime));
}

/* clearing the back buffer for drawing */
void Display::Clear(void) {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/* swapping the buffer after drawing */
void Display::Swap(void) {
        SDL_GL_SwapWindow(gWin);
}

/* cleanig up */
Display::~Display() {
        SDL_GL_DeleteContext(gCont);
        SDL_DestroyWindow(gWin);
        SDL_Quit();
}
