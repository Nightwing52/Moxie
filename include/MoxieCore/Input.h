#ifndef INPUT_H
#define INPUT_H

#include <array>
#include <cstring> //for using memcpy
#include <SDL2/SDL.h>

class Input {
        public:
                Input(bool showCursor);
                void Update(void);
                bool KeyPressed(SDL_Scancode key);
                bool KeyReleased(SDL_Scancode key);
                bool KeyHeld(SDL_Scancode key);
                bool ButtonPressed(int mouseButton);
                int GetXCoordinate(void);
                int GetYCoordinate(void);
                ~Input(void);
        private:
                SDL_Event event;
                /* keyboard states */
                const Uint8 *currentKeyboard;
                Uint8 *lastKeyboard;
                int length;
                int xCoordinate;
                int yCoordinate;
                int GetMouseCoordinates(void);
};

#endif
