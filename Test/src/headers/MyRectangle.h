//
//  MyRectangle.hpp
//  Lab1
//
//  Created by Tommy Bojanin on 1/31/19.
//  Copyright © 2019 Tommy Bojanin. All rights reserved.
//


#include "FrameBuffer.h"

#ifndef MyRectangle_h
#define MyRectangle_h
#include "Defines.h"

#endif /* MyRectangle_hpp */

class MyRectangle {

protected:
    color shapeColor;
    int x, y, width, height;

public:
    //initializer
    MyRectangle(int x = 0, int y = 0, int width = 50, int height = 100, color shapeColor = color(255, 255, 255, 1.0f));

    // method than can be overridden by subclasses
    virtual void draw(FrameBuffer &buff);

    //destructor
    ~MyRectangle(void);


    //Accessors and mutators
    int getX(void);
    int getY(void);
    color getColor(void);
    int getWidth(void);
    int getHeight(void);

    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setColor(color col);

};
