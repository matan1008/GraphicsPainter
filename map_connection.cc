#include "map_connection.h"

MapConnection::MapConnection(unsigned int map1_id, unsigned int x1, unsigned int y1, unsigned int map2_id, unsigned int x2, unsigned int y2)
{
	map1_id_ = map1_id;
	map2_id_ = map2_id;
	x1_ = x1;
	x2_ = x2;
	y1_ = y1;
	y2_ = y2;
}

MapConnection::~MapConnection()
{
}

unsigned int MapConnection::GetOtherMapId(unsigned int map_id)
{
	return ((map_id == map2_id_) ? map1_id_ : map2_id_);
}

unsigned int MapConnection::GetOtherMapX(unsigned int map_id)
{
	return ((map_id == map2_id_) ? x1_ : x2_);
}

unsigned int MapConnection::GetOtherMapY(unsigned int map_id)
{
	return ((map_id == map2_id_) ? y1_ : y2_);
}

unsigned int MapConnection::GetCurrentMapX(unsigned int map_id)
{
	return ((map_id == map1_id_) ? x1_ : x2_);
}

unsigned int MapConnection::GetCurrentMapY(unsigned int map_id)
{
	return ((map_id == map1_id_) ? y1_ : y2_);
}

unsigned int MapConnection::GetFirstMapId()
{
	return map1_id_;
}

unsigned int MapConnection::GetSecondMapId()
{
	return map2_id_;
}

void MapConnection::SetCurrentMapX(unsigned int map_id, unsigned int x)
{
	if (map_id == map1_id_)
	{
		x1_ = x;
	}
	else
	{
		x2_ = x;
	}
}
void MapConnection::SetCurrentMapY(unsigned int map_id, unsigned int y)
{
	if (map_id == map1_id_)
	{
		y1_ = y;
	}
	else
	{
		y2_ = y;
	}
}

bool MapConnection::IsRightConnection(unsigned int map_id, unsigned int x, unsigned int y)
{
	return (((map_id == map1_id_) && (x == x1_) && (y == y1_)) || ((map_id == map2_id_) && (x == x2_) && (y == y2_)));
}