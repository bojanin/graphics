/**
 * @author      : tommy (tommy@ven1xus-mbp)
 * @file        : Cylinder
 * @created     : Sunday Mar 31, 2019 12:44:30 EDT
 */

#ifndef CYLINDER_H
#define CYLINDER_H
#include "QuadricSurface.h"
#endif /* end of include guard CYLINDER_H */

class Cylinder: public QuadricSurface {
    public:
        double radius, length;

        Cylinder(const dvec3 position, double length, double radius, const color &mat);
        Cylinder(const dvec3 position, double length, double radius, const Material &material);

        HitRecord findClosestIntersection(const Ray & ray) override;
        
};
