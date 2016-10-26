#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "SDL2/SDL.h"
#include "GL/glew.h"

using namespace std;

class Display {
        public:
                Display(const string &title, const int width, const int height, const bool fullscreen);
                void SetFPS(const int newFPS);
                bool CheckExtensions(const string &glVersion, const string &extensions);
                bool IsActive(void);
                void LimitFPS(Uint32 lastTime); //send in the last time yo called SDL_GetTicks();
                void Clear(void);
                void Swap(void);
                ~Display();
        private:
                SDL_Window *gWin;
                SDL_GLContext gCont;
                SDL_Event *event;
                int FPS;
};

#endif
