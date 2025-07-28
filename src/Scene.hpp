#include "object.hpp"
#include <vector>

class Scene{
	static MovableObject player;
	static std::vector<Scene> scenes;

public:
	Object* blocks;//Array of all blocks in scene

	void SortThis(int index);
	void SetupObjects();

	Scene(unsigned short sizeOfArray);
};
