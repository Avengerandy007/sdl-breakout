#include "object.hpp"
#include <vector>

class Scene{
	static MovableObject player;
	static std::vector<Scene> scenes;

public:
	Object* blocks;//Array of all blocks in scene

	void SetupObjects();
	void RenderObjects();

	Scene(int amountOfBlocks);
};
