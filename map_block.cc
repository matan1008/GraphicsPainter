#include "map_block.h"

MapBlock::MapBlock(unsigned short ground_id, unsigned short object_id)
{
	ground_tile_ = MapTile::MapTile(ground_id);
	object_tile_ = MapTile::MapTile(object_id);
}

MapBlock::~MapBlock()
{

}

bool MapBlock::IsBlockingChar()
{
	return (ground_tile_.IsBlocking() || object_tile_.IsBlocking());
}

bool MapBlock::IsObjectTileExists()
{
	return (object_tile_.GetViewId() != 0x8000);
}

unsigned short MapBlock::GetGroundId()
{
	return ground_tile_.GetViewId();
}
unsigned short MapBlock::GetObjectId()
{
	return object_tile_.GetViewId();
}