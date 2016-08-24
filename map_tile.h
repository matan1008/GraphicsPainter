#pragma once
#ifndef GRAPHICS_MAPTILE_H_
#define GRAPHICS_MAPTILE_H_

class MapTile
{
public:
	MapTile();
	MapTile(unsigned short id);
	~MapTile();
	unsigned short GetViewId();
	void SetViewId(unsigned short id);
	bool IsBlocking();

private:
	unsigned short view_id_ = 0;
};
#endif // !GRAPHICS_MAPTILE_H_

