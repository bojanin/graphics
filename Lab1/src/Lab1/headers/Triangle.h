//
//  Triangle.hpp
//  Lab1
//
//  Created by Tommy Bojanin on 1/31/19.
//  Copyright © 2019 Tommy Bojanin. All rights reserved.
//

#ifndef MyRectangle_h
#include "MyRectangle.h"
#endif

#ifndef Triangle_h
#define Triangle_h

#endif /* Triangle_hpp */

class Triangle: MyRectangle {

public:
    Triangle(int x = 0, int y = 0, int base = 50, int height = 50, color shapeColor = color(255, 0, 255, 1.0f));

    void draw(FrameBuffer &buff) override;
};
