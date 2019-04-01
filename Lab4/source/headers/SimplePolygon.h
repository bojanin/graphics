/**
 * @author      : tommy (tommy@ven1xus-mbp)
 * @file        : SimplePolygon.h
 * @created     : Tuesday Mar 19, 2019 16:00:49 EDT
 */

#ifndef SIMPLEPOLYGON_H
#define SIMPLEPOLYGON_H
#include "Plane.h"
#endif /* end of include guard SIMPLEPOLYGON_H */

class SimplePolygon: public Plane {

    public:
        std::vector<dvec3> vertices;
        SimplePolygon(const std::vector<dvec3> &vertices, const color &material);
        
        HitRecord findClosestIntersection(const Ray &ray) override;
        bool isInside(const dvec3 &point);
};

