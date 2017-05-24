#include "Scene.h"

Scene::Scene(int type) {
}

int Scene::Run(void) {
	bool rendered = true;
	int inresult;
	while (rendered) {
		inresult = m_input.Poll();
		if (inresult = SDLK_ESCAPE)
			rendered = false;
	}
	return inresult;
}

Scene::~Scene() {
}
