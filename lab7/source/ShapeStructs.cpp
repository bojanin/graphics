#include "ShapeStructs.h"
#include "Lab.h"


Pyramid::Pyramid( color pyColor, double width, double height)
{
	color c = pyColor;

	dvec4 v0(0.0, height / 2.0, 0.0, 1.0);
	dvec4 v1(-width / 2.0, -height / 2.0, width / 2.0, 1.0);
	dvec4 v2(width / 2.0, -height / 2.0, width / 2.0, 1.0);
	dvec4 v3(width / 2.0, -height / 2.0, -width / 2.0, 1.0);
	dvec4 v4(-width / 2.0, -height / 2.0, -width / 2.0, 1.0);


	// Set vertex locations for one triangle
	dvec4 n(findUnitNormal(v0.xyz, v1.xyz, v2.xyz), 0.0);

	triangleVertices.push_back(VertexData(v0, c, n));
	triangleVertices.push_back(VertexData(v1, c, n));
	triangleVertices.push_back(VertexData(v2, c, n));

    n = dvec4(findUnitNormal(v0.xyz, v2.xyz, v3.xyz), 0.0);

    triangleVertices.push_back(VertexData(v0, c, n));
    triangleVertices.push_back(VertexData(v2, c, n));
    triangleVertices.push_back(VertexData(v3, c, n));

    n = dvec4(findUnitNormal(v0.xyz, v3.xyz, v4.xyz), 0.0);

    triangleVertices.push_back(VertexData(v0, c, n));
    triangleVertices.push_back(VertexData(v3, c, n));
    triangleVertices.push_back(VertexData(v4, c, n));

    n = dvec4(findUnitNormal(v0.xyz, v4.xyz, v1.xyz), 0.0);

    triangleVertices.push_back(VertexData(v0, c, n));
    triangleVertices.push_back(VertexData(v4, c, n));
    triangleVertices.push_back(VertexData(v1, c, n));

    n = dvec4(findUnitNormal(v1.xyz, v2.xyz, v3.xyz), 0.0);
                                                    
    triangleVertices.push_back(VertexData(v1, c, n));
    triangleVertices.push_back(VertexData(v2, c, n));
    triangleVertices.push_back(VertexData(v3, c, n));
                                                    
    n = dvec4(findUnitNormal(v3.xyz, v4.xyz, v1.xyz), 0.0);
                                                   
    triangleVertices.push_back(VertexData(v3, c, n));
    triangleVertices.push_back(VertexData(v4, c, n));
    triangleVertices.push_back(VertexData(v1, c, n));
}


ReferencePlane::ReferencePlane( double planeWidth, color c1, color c2 )
	: color1(c1), color2(c2)
{
	dvec4 n(0.0, 1.0, 0.0, 0.0);

	c1PlaneVertices.push_back(VertexData(dvec4(0.0, 0.0, 0.0, 1.0), color1, n));
	c1PlaneVertices.push_back(VertexData(dvec4(-planeWidth / 2.0, 0.0, -planeWidth / 2.0, 1.0), color1, n));
	c1PlaneVertices.push_back(VertexData(dvec4(-planeWidth / 2.0, 0.0, planeWidth / 2.0, 1.0), color1, n));
	c1PlaneVertices.push_back(VertexData(dvec4(0.0, 0.0, 0.0, 1.0), color1, n));
	c1PlaneVertices.push_back(VertexData(dvec4(planeWidth / 2.0, 0.0, planeWidth / 2.0, 1.0), color1, n));
	c1PlaneVertices.push_back(VertexData(dvec4(planeWidth / 2.0, 0.0, -planeWidth / 2.0, 1.0), color1, n));

	c2PlaneVertices.push_back(VertexData(dvec4(0.0, 0.0, 0.0, 1.0), color2, n));
	c2PlaneVertices.push_back(VertexData(dvec4(planeWidth / 2.0, 0.0, -planeWidth / 2.0, 1.0), color2, n));
	c2PlaneVertices.push_back(VertexData(dvec4(-planeWidth / 2.0, 0.0, -planeWidth / 2.0, 1.0), color2, n));
	c2PlaneVertices.push_back(VertexData(dvec4(0.0, 0.0, 0.0, 1.0), color2, n));
	c2PlaneVertices.push_back(VertexData(dvec4(-planeWidth / 2.0, 0.0, planeWidth / 2.0, 1.0), color2, n));
	c2PlaneVertices.push_back(VertexData(dvec4(planeWidth / 2.0, 0.0, planeWidth / 2.0, 1.0), color2, n));
}


dvec4 getSphericalCoordinate(double radius, double theta, double phi)
{
	dvec4 coord( radius * glm::cos(theta) * glm::sin(phi),
					 radius * glm::sin(theta) * glm::sin(phi),
					 radius * glm::cos(phi), 
					 1.0 );

	return coord;
}

