//
//  Rhombus.cpp
//  Lab1
//
//  Created by Tommy Bojanin on 2/1/19.
//  Copyright © 2019 Tommy Bojanin. All rights reserved.
//

#include "Parallelogram.h"

Parallelogram::Parallelogram(int x, int y, int width, int height, color shapeColor): MyRectangle(x, y, width, height, shapeColor) {}

void Parallelogram::draw(FrameBuffer &buff) {
    int skewedPixels = 0;
    for (int drawnYPixels = y; drawnYPixels <  y + height; drawnYPixels++) {
        for(int drawnXPixels = x + skewedPixels; drawnXPixels < x + width + skewedPixels; drawnXPixels++) {
            buff.setPixel(drawnXPixels, drawnYPixels, shapeColor);
        }
        skewedPixels++;
    }
}
