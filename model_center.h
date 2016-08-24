#pragma once
#ifndef GRAPHICS_MODELCENTER_H_
#define GRAPHICS_MODELCENTER_H_

#include "main_character.h"
#include "map_full.h"
#include "moveable_object.h"
#include <vector>

class ModelCenter
{
public:
	ModelCenter();
	~ModelCenter();
	void KeyPressed(unsigned char key_id);
	void MousePressed(unsigned char mouse_id);
	MapPart GetPrintableMap();
	std::vector<MoveableObject> GetPrintableMovables();

private:
	std::vector<MoveableObject> moveables_;
	MapFull map_;
};

#endif