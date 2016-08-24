#pragma once
#ifndef GRAPHICS_VIEWERCENTER_H_
#define GRAPHICS_VIEWERCENTER_H_

#include <iostream>
#include <windows.h>
#include <math.h>		
#include <stdio.h>		
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "load_shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
#include "model_center.h"
#include "graphic_vertex.h"
#include "graphic_tile.h"

class ViewCenter
{
public:
	ViewCenter();
	~ViewCenter();
	void SetModelCenter(ModelCenter &model_center);
	int InitGl();
	void Paint();
	bool ClosingWindowNotNeeded();
	void CloseWindow();
	void UpdateData();
	GLuint loadBMP_custom(const char * imagepath);
private:
	ModelCenter model_center_;
	unsigned int prev_map_id_ = 1;
	std::vector<GraphicTile> ground_map_;
	GraphicTile tile_;
	GLuint programId_;
	GLFWwindow* window_;
	GLuint Texture_;
	GLuint TextureID_;
	glm::mat4 mvp_;
	GLuint matrixId_;
};

ViewCenter::ViewCenter()
{

}

ViewCenter::~ViewCenter()
{
}

int ViewCenter::InitGl()
{
	if (!glfwInit())
	{
		return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window_ = glfwCreateWindow(1024, 768, "GRAPHICS", NULL, NULL);
	if (window_ == NULL)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window_);
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		return -1;
	}
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	programId_ = LoadShaders("TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader");
	//MatrixId_ = glGetUniformLocation(programId_, "MVP");
	glfwSetInputMode(window_, GLFW_STICKY_KEYS, GL_TRUE);
	return 0;
}

void ViewCenter::SetModelCenter(ModelCenter &model_center)
{
	model_center_ = model_center;
}

void ViewCenter::Paint()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(programId_);

	for (unsigned int i = 0; i < ground_map_.size(); ++i)
	{
		ground_map_[i].DrawTile();
		std::cout << i << ", " << ground_map_[i].GetX() << ", " << ground_map_[i].GetY() << ", " << ground_map_[i].GetSize() << std::endl;
	}
	//tile_.DrawTile();
	//std::cout << ", " << tile_.GetX() << ", " << tile_.GetY() << ", " << tile_.GetSize() << std::endl;
	glfwSwapBuffers(window_);
	glfwPollEvents();
}

bool ViewCenter::ClosingWindowNotNeeded()
{
	return ((glfwGetKey(window_, GLFW_KEY_ESCAPE) != GLFW_PRESS) && (glfwWindowShouldClose(window_) == 0));
}

void ViewCenter::CloseWindow()
{
	glDeleteProgram(programId_);
	glDeleteTextures(1, &TextureID_);
	glfwTerminate();
}
GLuint ViewCenter::loadBMP_custom(const char * imagepath)
{
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
							  // Actual RGB data
	unsigned char * data;
	FILE * file;
	fopen_s(&file, imagepath, "rb");
	if (!file) { printf("Image could not be opened\n"); return 0; }
	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return 0;
	}
	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way
										 // Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);
	// Create one OpenGL texture
	glGenTextures(1, &TextureID_);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, TextureID_);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
void ViewCenter::UpdateData()
{
	Texture_ = loadBMP_custom("Tiles/green.bmp");
	TextureID_ = glGetUniformLocation(programId_, "myTextureSampler");
	glm::mat4 Projection;
	glm::mat4 View;
	glm::mat4 Model = glm::mat4(1.0f);
	mvp_ = Projection * View * Model;
	matrixId_ = glGetUniformLocation(programId_, "MVP");
	MapPart tmp_map = model_center_.GetPrintableMap();
	int width, height;
	glfwGetWindowSize(window_, &width, &height);
	float size = (((tmp_map.GetWidth() / (float)width) > (tmp_map.GetHeight() / (float)height)) ? (2 / (float)tmp_map.GetWidth()) : (2 / (float)tmp_map.GetHeight()));
	//tile_ = GraphicTile(-1.0f + (size * 0), 1.0f - (size * 0), size);
	//tile_.SetGraphics(programId_, Texture_, TextureID_);
	for (int i = 0; i < tmp_map.GetHeight(); ++i)
	{
		for (int j = 0; j < tmp_map.GetWidth(); ++j)
		{
			GraphicTile *g_tile = new GraphicTile(-1.0f + (size * j), 1.0f - (size * i), size);
			g_tile->SetGraphics(programId_, Texture_, TextureID_, mvp_, matrixId_);
			ground_map_.push_back(*g_tile);
		}
	}
}


#endif // !GRAPHICS_VIEWERCENTER_H_
