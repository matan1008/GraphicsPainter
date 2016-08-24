#pragma once
#ifndef GLFW_LOADSHADER_H_
#define GLFW_LOADSHADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
#endif // !GLFW_LOADSHADER_H_
