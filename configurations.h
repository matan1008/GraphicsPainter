#pragma once
#ifndef GRAPHICS_CONFIGURATIONS_H_
#define GRAPHICS_CONFIGURATIONS_H_
namespace
{
	const unsigned int number_of_maps = 1;
	const char *maps_connections = "Maps\\maps_connections.pmapc";
	const char *pallet_town = "Maps\\map.pmap";
	const char *pallet_town_name = "Map";
	const char *maps_paths[number_of_maps] = {
		pallet_town
	};
	const char *maps_names[number_of_maps] = {
		pallet_town_name
	};
	const unsigned short init_x = 5, init_y = 5;
}
#endif // !GRAPHICS_CONFIGURATIONS_H_
