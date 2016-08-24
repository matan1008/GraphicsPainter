#include "map_part.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

MapPart::MapPart(unsigned int map_id, const char *filename, std::string map_name)
{
	map_id_ = map_id;
	map_name_ = map_name;
	std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		char * width_memblock = new char[4];
		char * height_memblock = new char[4];
		file.seekg(0, std::ios::beg);
		file.read((char *)&width_, 2);
		file.seekg(2, std::ios::beg);
		file.read((char *)&height_, 2);
		int total_len = (unsigned int)width_ * height_;
		char * map_memblock = new char[72];
		file.seekg(4, std::ios::beg);
		file.read(map_memblock, total_len);
		unsigned short ground_tile_id = 0, object_tile_id = 0;
		for (int i = 0; i < height_; i += 1)
		{
			for (int j = 0; j < width_; j += 4)
			{
				ground_tile_id = ((unsigned short)map_memblock[(width_ * i) + j] << 8) + (unsigned short)map_memblock[(width_ * i) + j + 1];
				object_tile_id = ((unsigned short)map_memblock[(width_ * i) + j + 2] << 8) + (unsigned short)map_memblock[(width_ * i) + j + 3];
				blocks_.push_back(MapBlock::MapBlock(ground_tile_id, object_tile_id));
			}
		}
	}
}

MapPart::~MapPart()
{
}

unsigned int MapPart::GetMapId()
{
	return map_id_;
}

unsigned short MapPart::GetWidth()
{
	return width_;
}
unsigned short MapPart::GetHeight()
{
	return height_;
}
MapBlock MapPart::GetBlock(unsigned short x, unsigned short y)
{
	return blocks_[(y * width_) + x];
}