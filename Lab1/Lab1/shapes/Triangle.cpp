//
//  Triangle.cpp
//  Lab1
//
//  Created by Tommy Bojanin on 1/31/19.
//  Copyright © 2019 Tommy Bojanin. All rights reserved.
//

#include "Triangle.h"

Triangle::Triangle(int x, int y, int base, int height, color col): MyRectangle(x, y, base, height, col) {}

// Blanks is the amount of blank spaces on each side of every horizontal line.
void Triangle::draw(FrameBuffer &buff) {
    int skewedPixels = 0;

    for (int drawnYPixels = y; drawnYPixels <  y + height; drawnYPixels++) {
        for(int drawnXPixels = x + skewedPixels; drawnXPixels < x + width - skewedPixels; drawnXPixels++) {
            buff.setPixel(drawnXPixels, drawnYPixels, shapeColor);
        }
        skewedPixels++;
    }
}
