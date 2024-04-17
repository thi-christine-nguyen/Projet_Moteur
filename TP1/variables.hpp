#ifndef VARIABLES_H_
#define VARIABLES_H_

#include "Camera.hpp"

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// General
GLFWwindow *window;
GLuint programID;

// Timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

// Camera
Camera camera(glm::vec3(-3.f, 6.f, 0.f), glm::vec3(0.f, 1.f, 0.0f));

// For speed computation
double lastTime = glfwGetTime();
double totalDeltaTime = 0.;
double physicsClock = 0.;
int nbFrames = 0;

// A suppr ce sera géré dans les GameObjects
std::vector<unsigned short> indices; //Triangles concaténés dans une liste
std::vector<std::vector<unsigned short> > triangles;
std::vector<glm::vec3> indexed_vertices;
std::vector<glm::vec2> uv;

// Get a handle for our "Model View Projection" matrices uniforms
glm::mat4 mat_m = glm::mat4(1); // Model

#endif