#ifndef SINGLETON_H
#define SINGLETON_H

#include "Display.h"
#include "Input.h"

class Singleton{
	public:
		static Singleton *getInstance(void);
		void add(Display *display);
		void add(Input *input);
		void update(void);
		~Singleton(void);
	private:
		static Singleton *singleton;
		Display *display;
		Input *input;
		Singleton(void);
		void initialize();
};
#endif