#pragma once
#ifndef GRAPHICS_MAPCONNECTION_H_
#define GRAPHICS_MAPCONNECTION_H_

class MapConnection
{
public:
	MapConnection(unsigned int map1_id, unsigned int x1, unsigned int y1, unsigned int map2_id, unsigned int x2, unsigned int y2);
	~MapConnection();
	unsigned int GetOtherMapId(unsigned int map_id);
	unsigned int GetOtherMapX(unsigned int map_id);
	unsigned int GetOtherMapY(unsigned int map_id);
	unsigned int GetCurrentMapX(unsigned int map_id);
	unsigned int GetCurrentMapY(unsigned int map_id);
	unsigned int GetFirstMapId();
	unsigned int GetSecondMapId();
	void SetCurrentMapX(unsigned int map_id, unsigned int x);
	void SetCurrentMapY(unsigned int map_id, unsigned int y);
	bool IsRightConnection(unsigned int map_id, unsigned int x, unsigned int y);

private:
	unsigned int map1_id_;
	unsigned int map2_id_;
	unsigned int x1_;
	unsigned int x2_;
	unsigned int y1_;
	unsigned int y2_;
};

#endif // !GRAPHICS_MAPCONNECTION_H_

