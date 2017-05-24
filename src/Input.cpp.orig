#include "Input.h"

/* setting up keyboard input */
Input::Input(bool showCursor) {
        if(showCursor)
                SDL_ShowCursor(SDL_ENABLE);
        else
                SDL_ShowCursor(SDL_DISABLE);
        currentKeyboard=SDL_GetKeyboardState(&length);
        lastKeyboard=new Uint8[length];
}

/* updating the keystate arrays */
void Input::Update(void) {
        /* storing last frame's array BEFORE updating */
        std::memcpy(lastKeyboard,currentKeyboard,length);
        SDL_PumpEvents();
}

/* testing if the key was pressed */
bool Input::KeyPressed(SDL_Scancode key){
         return(!lastKeyboard[key] && currentKeyboard[key]);
}

/* testing if the key was released */
bool Input::KeyReleased(SDL_Scancode key){
        return(lastKeyboard[key] && !currentKeyboard[key]);
}

/* testing if the key was held */
bool Input::KeyHeld(SDL_Scancode key){
        return(lastKeyboard[key] && currentKeyboard[key]);
}

/* testing if a button on the mouse is held; please pass in a SDL_BUTTON enum */
bool Input::ButtonPressed(int mouseButton){
        return(SDL_GetMouseState(NULL,NULL) & mouseButton);
}

/* getting the current 'x' coordinate */
int Input::GetXCoordinate(void){
        SDL_PumpEvents();
        SDL_GetMouseState(&xCoordinate,NULL);
        return xCoordinate;
}

/* getting the current 'y' coordinate */
int Input::GetYCoordinate(void){
        SDL_PumpEvents();
        SDL_GetMouseState(NULL,&yCoordinate);
        return yCoordinate;
}

/* cleaning up */
Input::~Input(void){
        delete lastKeyboard;
}
