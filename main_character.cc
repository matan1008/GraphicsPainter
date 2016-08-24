#pragma once
#include "main_character.h"

MainCharacter::MainCharacter()
{
	character_name_ = "";
}

MainCharacter::~MainCharacter()
{
}


void MainCharacter::SetCharacterName(std::string new_name)
{
	character_name_ = new_name;
}
