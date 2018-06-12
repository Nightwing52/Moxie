#include "Moxie.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
    Display *screen=new Display("Test", 720, 480, false);
    Input *input=new Input(true);
    Singleton *scene=Singleton::getInstance();
    scene->add(screen, input, Key::KEY_BACKSPACE);

    while(scene->isRunning()){
        scene->update();
    }

    delete scene;
	return 0;
}
