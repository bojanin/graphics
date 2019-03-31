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
        SimplePolygon(const std::vector<dvec3> vertices, const dvec3 &normal, const color &material);
};

