#include "Moxie.h"
#include <string>
#include <iostream>

glm::vec3 vertices[]={ glm::vec3(.0f, .5f, .0f), glm::vec3(-.5f, -.5f, .0f), glm::vec3(.5f, -.5f, .0f) };

int main(int argc, char *argv[]) {
	Display window("Hello Triangle", 720, 480, false);
	Input input(true);
	input.setDefaultCloseOperation(KEY_ESCAPE, &window);
	Mesh *mesh=Mesh::createMesh(vertices, 3, NULL, NULL);

	std::string error=window.getErrorLog();
	if(error.empty()){
		while(window.isRunning()) {
			input.update();
			mesh->draw();
			window.update();
		}
	}else
		std::cout<<error;
	return 0;
}
