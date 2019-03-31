/**
 * @author      : tommy (tommy@ven1xus-mbp)
 * @file        : Ellipsoid
 * @created     : Sunday Mar 31, 2019 12:12:04 EDT
 */

#include "Ellipsoid.h"


Ellipsoid::Ellipsoid(const dvec3 &position, double a, double b, double c, const color &mat) :
    QuadricSurface(position, mat), a(a), b(b), c(c) {
       A = 1/pow(a,2); 
       B = 1/pow(b,2); 
       C = 1/pow(c,2); 
       D = 0;
       E = 0;
       F = 0;
       G = 0;
       H = 0;
       I = 0;
       J = -1;
} 

Ellipsoid::Ellipsoid(const dvec3 &position, double a, double b, double c, const Material &material) :
    QuadricSurface(position, material), a(a), b(b), c(c) {
       A = 1/pow(a,2); 
       B = 1/pow(b,2); 
       C = 1/pow(c,2); 
       D = 0;
       E = 0;
       F = 0;
       G = 0;
       H = 0;
       I = 0;
       J = -1;
}
