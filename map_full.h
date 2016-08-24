#pragma once
#ifndef GRAPHICS_MAPFULL_H_
#define GRAPHICS_MAPFULL_H_

#include "map_part.h"
#include "map_connection.h"
#include "configurations.h"

class MapFull
{
public:
	MapFull();
	~MapFull();
	unsigned int GetCurrentMapId();
	MapPart GetCurrentMap();

private:
	void InitMapConnections(const char *filename);
	std::vector<MapConnection> map_connections_;
	std::vector<MapPart> map_parts_;
	unsigned int current_map_index_;
};


#endif // !GRAPHICS_MAPFULL_H_

