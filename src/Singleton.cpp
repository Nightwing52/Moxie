#include "Singleton.h"

Singleton *Singleton::singleton;

Singleton::Singleton(void){}

Singleton* Singleton::getInstance(void){
	if(Singleton::singleton == NULL)
		Singleton::singleton=new Singleton();
	return Singleton::singleton;
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

void Singleton::initialize(void){
	
}

void Singleton::update(void){
	display->update();
	input->update();
}

Singleton::~Singleton(void){
	delete input;
	delete display;
}
