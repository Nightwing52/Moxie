#include "Moxie.h"

int main(int argc, char *argv[]) {
	Display *window=new Display("Hello Triangle", 720, 480, false);
	Input input(true);
	input.setDefaultCloseOperation(KEY_ESCAPE, window);
	
	std::string error=window->getErrorLog();
	if(error.empty()){
		while(true) {
			window->update();
			input.update();
		}
	}else
		std::cout<<error;
	return 0;
}
