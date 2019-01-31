//
//  Square.hpp
//  Lab1
//
//  Created by Tommy Bojanin on 1/31/19.
//  Copyright © 2019 Tommy Bojanin. All rights reserved.
//

#ifndef MyRectangle_h
#include "MyRectangle.h"
#endif
#ifndef Square_h
#define Square_h

#endif /* Square_hpp */

class Square: public MyRectangle {
protected:
    int sideLength;
public:

    Square(int x = 0, int y = 0, int sideLength =  100, color shapeColor = color(255,255,255,1.0f));


    ~Square(void);


    //Accessors and mutators
    int getX(void);
    int getY(void);
    color getColor(void);
    int getWidth(void);
    int getHeight(void);

    void setX(int x);
    void setY(int y);
    void setSideLength(int sideLength);
    void setColor(color col);

};
