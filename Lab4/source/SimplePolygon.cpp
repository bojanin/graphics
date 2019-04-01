/**
 * @author      : tommy (tommy@ven1xus-mbp)
 * @file        : SimplePolygon
 * @created     : Tuesday Mar 19, 2019 16:00:28 EDT
 */

#include "SimplePolygon.h"

SimplePolygon::SimplePolygon(const std::vector<dvec3> &vertices, const color &material) 
    :Plane(vertices, material), vertices(vertices){ 

}

bool SimplePolygon::isInside(const dvec3& point) {
    bool backside = true, frontside = true;

    for(int i = 0; i < vertices.size(); i ++){
       dvec3 pointRay = point - vertices[i];
       dvec3 edge = vertices[(i + 1) % vertices.size()] - vertices[i];

       if (glm::dot(glm::cross(edge, pointRay), n) < 0) {
                        frontside = false;
        }
        if (glm::dot(glm::cross(edge, pointRay), n) > 0) {
                        backside = false;
        }
    }
      
    return backside || frontside;
}

HitRecord SimplePolygon::findClosestIntersection(const Ray &ray) {
   HitRecord h = Plane::findClosestIntersection(ray);
    h.surfaceNormal = n;
    
   if(h.t < FLT_MAX && !isInside(h.interceptPoint)) {
       h.t = FLT_MAX;
    } 
    return h; 
}

