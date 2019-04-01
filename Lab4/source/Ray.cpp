/**
 * @author      : tommy (tommy@ven1xus-mbp)
 * @file        : Ray
 * @created     : Sunday Mar 31, 2019 18:50:50 EDT
 */

#include "Ray.h"
#include "RayTracer.h"
#include "Surface.h"

HitRecord findIntersection(const Ray &ray, const SurfaceVector &surfaces) {
    HitRecord closest;
    HitRecord curr;

    for(auto s: surfaces) {
        curr = s->findClosestIntersection(ray);

        if(curr.t < closest.t) {
            closest = curr;
        }
    }
    return closest;
}
