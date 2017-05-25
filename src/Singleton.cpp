#include "Singleton.h"

Singleton::Singleton(void){}

Singleton* Singleton::getInstance(void){
	if(Singleton.singleton == NULL)
		Singleton.singleton=new Singleton();
	return Singleton.singleton;
}

void Singleton::add(Display *display){
	this->display=display;
	if(input != NULL)
		initialize();
}

void Singleton::add(Input *input){
	this->input=input;
	if(display != NULL)
		initialize();
}

Singleton::~Singleton(void){
	delete input;
	delete display;
}
