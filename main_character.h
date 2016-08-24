#pragma once
#ifndef GRAPHICS_MAINCHARACTER_H_
#define GRAPHICS_MAINCHARACTER_H_

#include <string>
#include "moveable_object.h"


class MainCharacter: public MoveableObject
{
public:
	MainCharacter();
	~MainCharacter();
	void SetCharacterName(std::string new_name);

private:
	std::string character_name_;
};


#endif // !GRAPHICS_MAINCHARACTER_H_

