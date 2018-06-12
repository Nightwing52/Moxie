#ifndef SINGLETON_H
#define SINGLETON_H

#include "Display.h"
#include "Input.h"

class Singleton{
	public:
		static Singleton *getInstance(void);
		void add(Display *display, Input *input, Key closeOn);
		void update(void);
		bool isRunning(void);
		~Singleton(void);
	private:
		static Singleton *singleton;
		Display *display;
		Input *input;
		Singleton(void);
		void initialize();
		bool running=true;
};
#endif
