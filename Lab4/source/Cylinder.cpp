/**
 * @author      : tommy (tommy@ven1xus-mbp)
 * @file        : Cylinder
 * @created     : Sunday Mar 31, 2019 12:44:16 EDT
 */
#include "Cylinder.h"

Cylinder::Cylinder(const dvec3 & position, const color & mat, double radius, double length)
: QuadricSurface(position, mat), radius(radius), length(length)
{
    B = 1.0 / pow(radius,2);
    C = 1.0 / pow(radius,2);
}

Cylinder::Cylinder(const dvec3 & position, const Material & mat, double radius, double length)
: QuadricSurface(position, mat), radius(radius), length(length)
{}


HitRecord Cylinder::findClosestIntersection(const Ray & ray) {
    HitRecord h = QuadricSurface::findClosestIntersection(ray);

    if (h.t == FLT_MAX)
    {
        return h;
    }

    if (glm::dot(h.surfaceNormal, ray.direct) < 0)
    {
       // h.surfaceNormal = -h.surfaceNormal;
    }

    float tmp = glm::length(h.interceptPoint - center);

    if (pow(tmp, 2) - pow(radius, 2) > pow(length / 2, 2))
    {
        h.t = FLT_MAX;
        Ray newRay;
        newRay.origin = h.interceptPoint + (ray.direct * EPSILON);
        newRay.direct = ray.direct;
        
        HitRecord newHR = Cylinder::findClosestIntersection(newRay);
        tmp = glm::length(newHR.interceptPoint - center); 
        if (pow(tmp, 2) - pow(radius, 2) < pow(length / 2, 2))
        {
            return newHR;
        }
    }

    return h;
}

