#include "model_center.h"

ModelCenter::ModelCenter()
{
	map_ = MapFull::MapFull();
	MainCharacter main_char = MainCharacter::MainCharacter();
	main_char.SetMapId(map_.GetCurrentMapId());
	main_char.SetX(init_x);
	main_char.SetY(init_y);
	moveables_.push_back(main_char);	
}

ModelCenter::~ModelCenter()
{

}

void ModelCenter::KeyPressed(unsigned char key_id)
{
	switch (key_id)
	{
	case 37: // <-
		moveables_[0].RotateLeft();
		break;

	case 38: // ^
		moveables_[0].MoveForward();
		break;
	
	case 39: // ->
		moveables_[0].RotateRight();
		break;

	default:
		break;
	}
}

MapPart ModelCenter::GetPrintableMap()
{
	return map_.GetCurrentMap();
}
std::vector<MoveableObject> ModelCenter::GetPrintableMovables()
{
	unsigned int current_map_id;
	current_map_id = map_.GetCurrentMapId();
	std::vector<MoveableObject> ret_moveables;
	for (unsigned int i = 0; i < moveables_.size(); ++i)
	{
		if (moveables_[i].GetMapId() == current_map_id)
		{
			ret_moveables.push_back(moveables_[i]);
		}
	}
	return ret_moveables;
}