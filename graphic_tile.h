#pragma once
#ifndef GRAPHICS_GRAPHICTILE_H_

#include "graphic_triangle.h"
#include <vector>
#include <array>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

class GraphicTile
{
public:
	GraphicTile();
	GraphicTile(float x, float y, float size);
	void SetGraphics(GLuint programId, GLuint texture, GLuint texture_id, glm::mat4 mvp, GLuint matrixId);
	~GraphicTile();
	void DrawTile();
	float GetX();
	float GetY();
	float GetSize();
	
private:
	std::vector<float> vertexes_;
	glm::mat4 mvp_;
	GLuint matrixId_;
	GLuint texture_;
	GLuint texture_id_;
	GLuint vertexbuffer_;
	GLuint uvbuffer_;
	GLuint vertexArrayId_;
	std::array<float, 12> uv_data_ = {
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
	};
};

GraphicTile::GraphicTile()
{
	vertexes_.reserve(18);
}

GraphicTile::GraphicTile(float x, float y, float size)
{
	vertexes_.reserve(18);
	vertexes_.insert(vertexes_.begin(), { x, y, 0.0f, x+size, y, 0.0f, x, y-size, 0.0f, x, y-size, 0.0f, x+size, y, 0.0f, x+size, y-size, 0.0f });
}

float GraphicTile::GetX()
{
	return vertexes_[0];
}
float GraphicTile::GetY()
{
	return vertexes_[1];
}
float GraphicTile::GetSize()
{
	return (vertexes_[3] - vertexes_[0]);
}

void GraphicTile::SetGraphics(GLuint programId, GLuint texture, GLuint texture_id, glm::mat4 mvp, GLuint matrixId)
{
	/*glm::mat4 Projection;
	glm::mat4 View;
	glm::mat4 Model = glm::mat4(1.0f);
	mvp_ = Projection * View * Model;
	matrixId_ = glGetUniformLocation(programId, "MVP");*/
	mvp_ = mvp;
	matrixId_ = matrixId;
	texture_ = texture;
	texture_id_ = texture_id;

	glGenVertexArrays(1, &vertexArrayId_);
	glBindVertexArray(vertexArrayId_);

	glGenBuffers(1, &vertexbuffer_);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer_);
	glBufferData(GL_ARRAY_BUFFER, vertexes_.size() * sizeof(vertexes_[0]), &vertexes_[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer_);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer_);
	glBufferData(GL_ARRAY_BUFFER, uv_data_.size() * sizeof(uv_data_[0]), &uv_data_[0], GL_STATIC_DRAW);
}

GraphicTile::~GraphicTile()
{
	glDeleteBuffers(1, &vertexbuffer_);
	glDeleteVertexArrays(1, &vertexArrayId_);
	glDeleteBuffers(1, &uvbuffer_);
}

void GraphicTile::DrawTile()
{
	glUniformMatrix4fv(matrixId_, 1, GL_FALSE, &mvp_[0][0]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture_);
	glUniform1i(texture_id_, 0);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer_);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer_);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 3 * 2);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}


#endif // !GRAPHICS_GRAPHICTILE_H_
