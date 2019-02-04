#pragma once

#include <iostream> // Stream input and output operations
#include <vector> // Sequence containers for arrays that can change in size
#include <memory> // General utilities to manage dynamic memory

// Glut takes care of all the system-specific chores required for creating windows, 
// initializing OpenGL contexts, and handling input events
#include <GL/freeglut.h>

// Initialize matrices to Identity and vectors to zero vector
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

// Attenuation factors
#define CONSTANT_ATTEN 1.0
#define LINEAR_ATTEN 0.01
#define QUADRATIC_ATTEN 0.001

#define WINDOW_WIDTH 512 // Default window width in pixels
#define WINDOW_HEIGHT 316 // Default window height in pixels = width/1.618

// Small value used to create offset to avoid "surface acne"
#define EPSILON 1.0E-4

// Define pi as type double.
#define M_PI glm::pi<double>()

// Allow reference to vec4 as a "color"
#define color dvec4

// Using statements to make identifiers from another namespace available without qualification
using std::cout;
using std::endl;

using glm::dvec2;
using glm::dvec3;
using glm::dvec4;
using glm::dmat2;
using glm::dmat3;
using glm::dmat4;

// Function for generating random colors. Alpha value is always 
// set to 1.0
color getRandomColor();

// Simple functions for printing vectors and matrices to the console
void print(const glm::dvec2 & v0);

void print(const glm::dvec3 & v0);

void print(const glm::dvec4 & v0);

void print(const glm::dmat2 & m);

void print(const glm::dmat3 & m);

void print(const glm::dmat4 & m);

