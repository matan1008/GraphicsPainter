#include "moveable_object.h"

MoveableObject::MoveableObject()
{

}

MoveableObject::~MoveableObject()
{

}

void MoveableObject::RotateRight()
{
	switch (direction_)
	{
	case Direction::UP:
		direction_ = Direction::RIGHT;
		break;
	case Direction::RIGHT:
		direction_ = Direction::DOWN;
		break;
	case Direction::DOWN:
		direction_ = Direction::LEFT;
		break;
	case Direction::LEFT:
		direction_ = Direction::UP;
		break;
	}
}

void MoveableObject::RotateLeft()
{
	switch (direction_)
	{
	case Direction::UP:
		direction_ = Direction::LEFT;
		break;
	case Direction::RIGHT:
		direction_ = Direction::UP;
		break;
	case Direction::DOWN:
		direction_ = Direction::RIGHT;
		break;
	case Direction::LEFT:
		direction_ = Direction::DOWN;
		break;
	}
}

void MoveableObject::MoveForward()
{
	switch (direction_)
	{
	case Direction::UP:
		--y_location_;
		break;
	case Direction::RIGHT:
		++x_location_;
		break;
	case Direction::DOWN:
		++y_location_;
		break;
	case Direction::LEFT:
		--x_location_;
		break;
	}
}

unsigned short MoveableObject::GetX()
{
	return x_location_;
}

unsigned short MoveableObject::GetY()
{
	return y_location_;
}

void MoveableObject::SetX(unsigned short x)
{
	x_location_ = x;
}

void MoveableObject::SetY(unsigned short y)
{
	y_location_ = y;
}

unsigned int MoveableObject::GetMapId()
{
	return map_id_;
}
void MoveableObject::SetMapId(unsigned int map_id)
{
	map_id_ = map_id;
}