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
    int blanks = 0;

    //Outer for-loop dictates height of the triangle
    for(int currYPixel = getY(); currYPixel < getY() + getHeight(); currYPixel++) {
        int currXPixel = getX();

        // move the current X pixel over the correct amount of blanks spaces
        // ON THE LEFT SIDE of triangle
        while(currXPixel < blanks) {
            currXPixel++;
        }

        int amountOfPixels = 0;

        //color in correct amount of pixels in before the blank space on the right side.
        while(amountOfPixels < getWidth() - blanks) {
            buff.setPixel(currXPixel, currYPixel, shapeColor);
            amountOfPixels++;
            currXPixel++;
        }
        blanks++;
    }
}
