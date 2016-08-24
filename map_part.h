#pragma once
#ifndef GRAPHICS_MAPPART_H_
#define GRAPHICS_MAPPART_H_
#include <vector>
#include <string>
#include "map_block.h"

class MapPart
{
public:
	MapPart(unsigned int map_id, const char *filename, std::string map_name);
	~MapPart();
	unsigned int GetMapId();
	unsigned short GetWidth();
	unsigned short GetHeight();
	MapBlock GetBlock(unsigned short x, unsigned short y);

private:
	std::string map_name_;
	unsigned int map_id_;
	std::vector<MapBlock> blocks_;
	unsigned short width_;
	unsigned short height_;
};
#endif // !GRAPHICS_MAPPART_H_
