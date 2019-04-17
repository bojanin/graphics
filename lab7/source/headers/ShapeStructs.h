#pragma once

#include "Defines.h"
#include "lab.h"
#include "VertexData.h"

struct ReferencePlane
{
	ReferencePlane( double planeWidth = 8.0, 
					color c1 = color(0.0, 0.0, 0.0, 1.0), 
					color c2 = color(1.0, 1.0, 1.0, 1.0));

	color color1;
	color color2;

	std::vector<VertexData> c1PlaneVertices;
	std::vector<VertexData> c2PlaneVertices;

};


struct Pyramid
{
	Pyramid(color pyColor, double width = 1.0, double height = 1.0);

	std::vector<VertexData> triangleVertices;
};




