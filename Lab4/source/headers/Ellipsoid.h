/**
 * @author      : tommy (tommy@ven1xus-mbp)
 * @file        : Ellipsoid
 * @created     : Sunday Mar 31, 2019 12:12:20 EDT
 */

#ifndef ELLIPSOID_H
#define ELLIPSOID_H
#include "QuadricSurface.h"
#endif /* end of include guard ELLIPSOID_H */

class Ellipsoid: public QuadricSurface {
    public:
        double a,b,c;

        Ellipsoid(const dvec3 &position, double a, double b, double c, const color &mat);
        Ellipsoid(const dvec3 &position, double a, double b, double c, const Material &material);
};
