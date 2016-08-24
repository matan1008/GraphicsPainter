#pragma once
#ifndef GRAPHICS_GRAPHICVERTEX_H_
#define GRAPHICS_GRAPHICVERTEX_H_

class GraphicVertex
{
public:
	GraphicVertex(float x, float y, float z, float u, float v);
	~GraphicVertex();
	float x_, y_, z_, u_, v_;
private:

};


#endif // !GRAPHICS_GRAPHICVERTEX_H_
