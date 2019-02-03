//
//  Rhombus.hpp
//  Lab1
//
//  Created by Tommy Bojanin on 2/1/19.
//  Copyright © 2019 Tommy Bojanin. All rights reserved.
//
#ifndef MyRectangle_h
#include "MyRectangle.h"
#endif

#ifndef Parallelogram_h
#define Parallelogram_h
#endif /* Rhombus_hpp */

class Parallelogram: MyRectangle {
public:
    Parallelogram(int x = 0, int y = 0, int width = 100, int height = 50, color shapeColor = color(200,100,150, 1.0f));
    void draw(FrameBuffer &buff) override;
};
