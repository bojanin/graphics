//
//  Square.cpp
//  Lab1
//
//  Created by Tommy Bojanin on 1/31/19.
//  Copyright © 2019 Tommy Bojanin. All rights reserved.
//

#include "Square.h"

Square::Square(int x, int y, int sideLength, color shapeColor): MyRectangle(x,y, sideLength, sideLength, shapeColor) {}

int Square::getX() {
    return MyRectangle::getX();
}

Square::~Square() {
    
}

int Square::getY() {
    return MyRectangle::getY();
}
int Square::getWidth() {
    return MyRectangle::getWidth();
}
int Square::getHeight() {
    return MyRectangle::getHeight();
}

color Square::getColor() {
    return MyRectangle::getColor();
}

void Square::setX(int x){
    MyRectangle::setX(x);
}

void Square::setY(int y){
    MyRectangle::setY(y);
}

void Square::setSideLength(int sideLength) {
    this->sideLength = sideLength;
    MyRectangle::setWidth(sideLength);
    MyRectangle::setHeight(sideLength);
}

void Square::setColor(color col) {
    MyRectangle::setColor(col);
}

