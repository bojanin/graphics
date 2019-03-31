/**
 * @author      : tommy (tommy@ven1xus-mbp)
 * @file        : SimplePolygon
 * @created     : Tuesday Mar 19, 2019 16:00:28 EDT
 */

#include "SimplePolygon.h"

SimplePolygon::SimplePolygon(const std::vector<dvec3> vertices, const dvec3 &normal, const color &material) 
    :Plane(vertices, material) { 

}


