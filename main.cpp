#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Input.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main(int argc, char *argv[]) {
        try {
                Display screen("Windfall", 1600, 900);
                Shader vshad("/usr/local/share/windfall/shaders/vs.glsl", GL_VERTEX_SHADER);
                Shader fshad("/usr/local/share/windfall/shaders/fs.glsl", GL_FRAGMENT_SHADER);
                Mesh model("/usr/local/share/windfall/models/thing.mox");
                Input input;
                
                bool running = true;
                while (running) {
                        screen.Clear();
                        switch (input.Poll()) {
                                case SDL_QUIT:
                                        running = false;
                                        break;
                                default:
                                        break;
                        }
                        screen.Swap();
                }
        } catch (exception &e) {
                cerr << "Fatal error: " << e.what() << endl;
                return -1;
        }
        return 0;
}
