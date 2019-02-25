#include "RayTracer.h"


RayTracer::RayTracer(FrameBuffer & cBuffer, color defaultColor )
:colorBuffer(cBuffer), defaultColor(defaultColor), recursionDepth(2)
{
    	
}


void RayTracer::setCameraFrame(const dvec3 & viewPosition, const dvec3 & viewingDirection, dvec3 up)
{
	// TODO

} // end setCameraFrame


void RayTracer::calculatePerspectiveViewingParameters(const double & verticalFieldOfViewDegrees)
{

	// TODO

	renderPerspectiveView = true; // generate perspective view rays
	
} // end calculatePerspectiveViewingParameters


void RayTracer::calculateOrthographicViewingParameters(const double & viewPlaneHeight)
{
	topLimit = fabs(viewPlaneHeight) / 2.0;

	rightLimit = topLimit * ((double)colorBuffer.getWindowWidth()/colorBuffer.getWindowHeight()); // Set r based on aspect ratio and height of plane

	// Make view plane symetrical about the viewing direction
	leftLimit = -rightLimit; 
	bottomLimit = -topLimit;

	// Calculate the distance between pixels in the horizontal and vertical directions
	nx = (double)colorBuffer.getWindowWidth();
	ny = (double)colorBuffer.getWindowHeight();

	distToPlane = 0.0; // Rays start on the view plane

	renderPerspectiveView = false; // generate orthographic view rays
	
} // end calculateOrthographicViewingParameters


void RayTracer::raytraceScene(const SurfaceVector & surfaces, const LightVector & lights)
{
	this->surfacesInScene = surfaces;
	this->lightsInScene = lights;

	// Iterate through each and every pixel in the rendering window

    for(int i = 0; i < colorBuffer.getWindowWidth(); i ++) {
        for(int j = 0; j < colorBuffer.getWindowHeight(); i++) {
            colorBuffer.setPixel(i, j, defaultColor);
        }
    }
} // end raytraceScene



color RayTracer::traceIndividualRay(const Ray & viewRay, int recursionLevel)
{
	// Find surface intersection that is closest to 'e' in the direction 'd.'
	// TODO


	return defaultColor;


} // end traceRay


Ray RayTracer::getOrthoViewRay( const int x, const int y)
{
	Ray orthoViewRay;

	dvec2 uv = getImagePlaneCoordinates(x, y);
	
	orthoViewRay.origin = eye + uv.x * u + uv.y * v;
	orthoViewRay.direct = glm::normalize( -w );

	return orthoViewRay;

} // end getOrthoViewRay


Ray RayTracer::getPerspectiveViewRay(const int x, const int y)
{
	Ray perspectiveViewRay;

	// TODO

	return perspectiveViewRay;

} // end getPerspectiveViewRay


dvec2 RayTracer::getImagePlaneCoordinates(const int x, const int y)
{

	dvec2 uv;

	// TODO

	return uv;
}





