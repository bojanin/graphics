#pragma once
#define GL_SILENCE_DEPRECATION 
#include <iostream> // Stream input and output operations
#include <vector> // Sequence containers for arrays that can change in size
#include <memory> // General utilities to manage dynamic memory

// Glut takes care of all the system-specific chores required for creating windows, 
// initializing OpenGL contexts, and handling input events
#include <GLUT/GLUT.h>

#define GLM_FORCE_CTOR_INIT

// Forward declaration to speed compilation
#include "glm/fwd.hpp"

// Basic GLM functionality
#include "glm/glm.hpp"

// Stable glm extensions
// https://glm.g-truc.net/0.9.9/api/a01364.html
#include <glm/gtc/matrix_transform.hpp>
// https://glm.g-truc.net/0.9.9/api/a00437.html
#include <glm/gtc/type_ptr.hpp>
// https://glm.g-truc.net/0.9.9/api/a00395.html
#include <glm/gtc/constants.hpp>
// https://glm.g-truc.net/0.9.9/api/a01370.html
#include <glm/gtc/quaternion.hpp>

// Allows experimental extensions of glm to be used
#define GLM_ENABLE_EXPERIMENTAL

// For simple scale, rotate, and translate functions
// https://glm.g-truc.net/0.9.9/api/a00596.html
#include <glm/gtx/transform.hpp>
// For additional quaterion functionality
// https://glm.g-truc.net/0.9.9/api/a01373.html
#include <glm/gtx/quaternion.hpp> 
// https://glm.g-truc.net/0.9.9/api/a00736.html#gae6aa26ccb020d281b449619e419a609e
#include <glm/gtx/euler_angles.hpp>

// #defines for text substitution in source code prior to compile

#define color glm::vec4

// Attenuation factors
#define CONSTANT_ATTEN 1.0f
#define LINEAR_ATTEN 0.01f
#define QUADRATIC_ATTEN 0.001f

#define WINDOW_WIDTH 1024 // Default window width in pixels
#define WINDOW_HEIGHT 1024 // Default window height in pixels = width/1.618

// Small value used to create offset to avoid "surface acne"
#define EPSILON 1.0E-4f

#define M_PI glm::pi<double>()

// Function for generating random colors. Alpha value is always 
// set to 1.0
color getRandomColor();

// Simple functions for printing vectors and matrices to the console
void print(const glm::vec2 & v0);

void print(const glm::vec3 & v0);

void print(const glm::vec4 & v0);

void print(const glm::mat2 & m);

void print(const glm::mat3 & m);

void print(const glm::mat4 & m);

