#pragma once
#ifndef GRAPHICS_GRAPHICTRIANGLE_H_
#define GRAPHICS_GRAPHICTRIANGLE_H_

#include <vector>
#include "graphic_vertex.h"

class GraphicTriangle
{
public:
	GraphicTriangle();
	GraphicTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	~GraphicTriangle();
	std::vector<float> vertexes_;
private:

};

GraphicTriangle::GraphicTriangle()
{
	vertexes_.reserve(9);
}

GraphicTriangle::GraphicTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	vertexes_.reserve(9);
	vertexes_.push_back(x1);
	vertexes_.push_back(y1);
	vertexes_.push_back(z1);
	vertexes_.push_back(x2);
	vertexes_.push_back(y2);
	vertexes_.push_back(z2);
	vertexes_.push_back(x3);
	vertexes_.push_back(y3);
	vertexes_.push_back(z3);
}

GraphicTriangle::~GraphicTriangle()
{
}
#endif // !GRAPHICS_GRAPHICTRIANGLE_H_
