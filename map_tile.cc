#include "map_tile.h"

MapTile::MapTile()
{
	
}

MapTile::MapTile(unsigned short id)
{
	view_id_ = id;
}

MapTile::~MapTile()
{

}

unsigned short MapTile::GetViewId()
{
	return view_id_;
}

void MapTile::SetViewId(unsigned short id)
{
	view_id_ = id;
}

bool MapTile::IsBlocking()
{
	return (((view_id_ >> 15) & 1) == 1);
}