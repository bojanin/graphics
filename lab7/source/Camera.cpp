#include "Camera.h"

Camera::Camera(dvec3 position, dvec3 direction, dvec3 up) {
    viewTrans = glm::lookAt(position, direction, up);
}

Camera::~Camera() {}

glm::dvec3 Camera::getWorldCoordinateViewPosition() {
    return glm::inverse(viewTrans)[3].xyz;
}


glm::dmat4 Camera::getViewingTransformation() {
    return viewTrans;
}

void Camera::view(glm::dvec3 position, glm::dvec3 direction, glm::dvec3 up) {
	viewTrans = glm::lookAt(position, direction, up);
}