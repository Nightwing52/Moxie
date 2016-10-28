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

/* remapping some of hte default SDL2 enums to something more user friendly */
namespace rm{
        enum class Key : int{
                /* mouse buttons */
                LEFT_CLICK=SDL_BUTTON_LEFT,
                RIGHT_CLICK=SDL_BUTTON_RIGHT,
                MIDDLE_CLICK=SDL_BUTTON_MIDDLE,
                /* arrow keys */
                UP=SDL_SCANCODE_UP,
                DOWN=SDL_SCANCODE_DOWN,
                LEFT=SDL_SCANCODE_LEFT,
                RIGHT=SDL_SCANCODE_RIGHT,
                /* letters */
                A=SDL_SCANCODE_A,
                B=SDL_SCANCODE_B,
                C=SDL_SCANCODE_C,
                D=SDL_SCANCODE_D,
                E=SDL_SCANCODE_E,
                F=SDL_SCANCODE_F,
                G=SDL_SCANCODE_G,
                H=SDL_SCANCODE_H,
                I=SDL_SCANCODE_I,
                J=SDL_SCANCODE_J,
                K=SDL_SCANCODE_K,
                L=SDL_SCANCODE_L,
                M=SDL_SCANCODE_M,
                N=SDL_SCANCODE_N,
                O=SDL_SCANCODE_O,
                P=SDL_SCANCODE_P,
                Q=SDL_SCANCODE_Q,
                R=SDL_SCANCODE_R,
                S=SDL_SCANCODE_S,
                T=SDL_SCANCODE_T,
                U=SDL_SCANCODE_U,
                V=SDL_SCANCODE_V,
                W=SDL_SCANCODE_W,
                X=SDL_SCANCODE_X,
                Y=SDL_SCANCODE_Y,
                Z=SDL_SCANCODE_Z,
                /* numbers */
                ZERO=SDL_SCANCODE_0,
                ONE=SDL_SCANCODE_1,
                TWO=SDL_SCANCODE_2,
                THREE=SDL_SCANCODE_3,
                FOUR=SDL_SCANCODE_4,
                FIVE=SDL_SCANCODE_5,
                SIX=SDL_SCANCODE_6,
                SEVEN=SDL_SCANCODE_7,
                EIGHT=SDL_SCANCODE_8,
                NINE=SDL_SCANCODE_9,
                /* special characters */
                SHIFT_LEFT=SDL_SCANCODE_LSHIFT,
                SHIFT_RIGHT=SDL_SCANCODE_RSHIFT,
                TAB=SDL_SCANCODE_TAB,
                CAPS_LOCK=SDL_SCANCODE_CAPSLOCK,
                TILDE=SDL_SCANCODE_GRAVE,
                LEFT_CONTROL=SDL_SCANCODE_LCTRL,
                RIGHT_CONTROL=SDL_SCANCODE_RCTRL,
                LEFT_ALT=SDL_SCANCODE_LALT,
                RIGHT_ALT=SDL_SCANCODE_RALT,
                ENTER=SDL_SCANCODE_RETURN,
                BACKSPACE=SDL_SCANCODE_BACKSPACE,
                ESCAPE=SDL_SCANCODE_ESCAPE
        };
}

#endif
