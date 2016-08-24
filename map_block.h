#pragma once
#ifndef GRAPHICS_MAPBLOCK_H_
#define GRAPHICS_MAPBLOCK_H_

#include "map_tile.h"

class MapBlock
{
public:
	MapBlock(unsigned short ground_id, unsigned short object_id);
	~MapBlock();
	bool IsBlockingChar();
	bool IsObjectTileExists();
	unsigned short GetGroundId();
	unsigned short GetObjectId();


private:
	MapTile ground_tile_;
	MapTile object_tile_;
};
#endif // !GRAPHICS_MAPBLOCK_H_
