#pragma once
#ifndef GRAPHICS_MOVEABLEOBJECT_H_
#define GRAPHICS_MOVEABLEOBJECT_H_

enum class Direction {UP, RIGHT, DOWN, LEFT};

class MoveableObject
{
public:
	MoveableObject();
	~MoveableObject();
	void RotateRight();
	void RotateLeft();
	void MoveForward();
	unsigned short GetX();
	unsigned short GetY();
	void SetX(unsigned short x);
	void SetY(unsigned short y);
	unsigned int GetMapId();
	void SetMapId(unsigned int map_id);

private:
	unsigned short x_location_, y_location_;
	unsigned int map_id_;
	Direction direction_ = Direction::UP;
};

#endif
