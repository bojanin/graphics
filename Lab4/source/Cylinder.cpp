/**
 * @author      : tommy (tommy@ven1xus-mbp)
 * @file        : Cylinder
 * @created     : Sunday Mar 31, 2019 12:44:16 EDT
 */

#include "Cylinder.h"

Cylinder::Cylinder(const dvec3 position, double length, double radius, const color &mat) 
    : QuadricSurface(position, mat), length(length), radius(radius) {

    }

Cylinder::Cylinder(const dvec3 position, double length, double radius, const Material &material) 
    : QuadricSurface(position, material), length(length), radius(radius) {

    }

HitRecord Cylinder::findClosestIntersection(const Ray &ray) {
    HitRecord h = QuadricSurface::findClosestIntersection(ray);
    
    }
