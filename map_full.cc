#include "map_full.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

MapFull::MapFull()
{
	for (int i = 0; i < number_of_maps; ++i)
	{
		map_parts_.push_back(MapPart::MapPart(i, maps_paths[i], maps_names[i]));
	}
	InitMapConnections(maps_connections);
	current_map_index_ = 0;
}

MapFull::~MapFull()
{
}

void MapFull::InitMapConnections(const char *filename)
{
	std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		char * width_memblock = new char[4];
		char * height_memblock = new char[4];
		file.seekg(0, std::ios::beg);
		std::string line;
		unsigned int first_map_id, second_map_id, x1, x2, y1, y2;
		while (std::getline(file, line))
		{
			first_map_id = atoi(line.substr(0, 4).c_str());
			x1 = atoi(line.substr(0, 4).c_str());
			y1 = atoi(line.substr(0, 4).c_str());
			second_map_id = atoi(line.substr(0, 4).c_str());
			x2 = atoi(line.substr(0, 4).c_str());
			y2 = atoi(line.substr(0, 4).c_str());
			map_connections_.push_back(MapConnection::MapConnection(first_map_id, x1, y1, second_map_id, x2, y2));
		}
	}
}

unsigned int MapFull::GetCurrentMapId()
{
	return current_map_index_;
}

MapPart MapFull::GetCurrentMap()
{
	return map_parts_[current_map_index_];
}