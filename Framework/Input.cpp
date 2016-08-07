#include "Input.h"

Input::Input() {
}

int Input::Poll(void) {
        SDL_PollEvent(&event);
        return event.type;
}
