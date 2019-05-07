#pragma once

#include "Defines.h"
#include "Lab.h"
#include "VertexData.h"

struct Shape {

    virtual void draw();
    virtual void setPosition(const dvec3 &positionVector);
    virtual void setOrientation(const double &angle, const dvec3 &axis); 

    virtual void setScale(const double &scaleValue);

    protected:
    dmat4 orientation;
    dmat4 position;
    dmat4 scale;

    std::vector<VertexData> triangleVertices;
};

struct ReferencePlane: public Shape
{
	ReferencePlane( double planeWidth = 8.0, 
					color c1 = color(0.0, 0.0, 0.0, 1.0), 
					color c2 = color(1.0, 1.0, 1.0, 1.0));

	color color1;
	color color2;
};


struct Pyramid: public Shape
{
	Pyramid(color pyColor, double width = 1.0, double height = 1.0);
};


struct Sphere: public Shape {
    Sphere(color col, double radius = 0.5f, int slices = 16, int stacks = 16);

    Material material;

    protected:
    void initializeTop();
    void initializeBody();
    void initializeBottom();
    
    int stacks, slices;
    double radius;      

    std::vector<double> stackAngles;
    std::vector<double> sliceAngles;

};

struct Box : public Shape
{
Box( color cubeColor = color(1.0f, 1.0f, 0.0f, 1.0f),
         float width = 1.0f, float height = 1.0f, float depth = 1.0f);
};


