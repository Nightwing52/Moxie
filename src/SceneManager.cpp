#include "SceneManager.h"

SceneManager::SceneManager() {
}

void SceneManager::CreateScene(int type) {
	sceneStack.emplace(Scene(type));
}

int SceneManager::RunTop(void) {
	Scene tmp = sceneStack.top();
	return tmp.Run();
}

SceneManager::~SceneManager() {
	while(!sceneStack.empty()) {
		sceneStack.pop();
	}
}
