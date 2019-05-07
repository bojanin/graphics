#include "Defines.h"

struct Camera
{
	

	Camera( glm::dvec3 position = glm::dvec3(0.0, 0.0, 0.0), 
		  	glm::dvec3 direction = glm::dvec3(0.0, 0.0, -1.0),
 			glm::dvec3 up = glm::dvec3(0.0, 1.0, 0.0) );

	~Camera();


	

	glm::dvec3 getWorldCoordinateViewPosition();

	glm::dmat4 getViewingTransformation();
	void view(glm::dvec3 position = glm::dvec3(0.0, 0.0, 0.0), glm::dvec3 direction = glm::dvec3(0.0, 0.0, -1.0),glm::dvec3 up = glm::dvec3(0.0, 1.0, 0.0));
	glm::dmat4 viewTrans;

	
};
