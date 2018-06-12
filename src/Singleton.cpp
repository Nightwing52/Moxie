#include "Singleton.h"

Singleton *Singleton::singleton=new Singleton();

Singleton::Singleton(void){}

Singleton* Singleton::getInstance(void){
	return Singleton::singleton;
}

void Singleton::add(Display *display, Input *input, Key closeOn){
    this->display=display;
	this->input=input;
	this->input->setDefaultCloseOperation(closeOn, this->display);
}

void Singleton::update(void){
    if(this->input->update() == true)
        this->running=false;
	this->display->update();
}

bool Singleton::isRunning(void){
    return this->running;
}

Singleton::~Singleton(void){
	delete this->input;
	delete this->display;
}
