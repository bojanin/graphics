//
//  MyRectangle.cpp
//  Lab1
//
//  Created by Tommy Bojanin on 1/31/19.
//  Copyright © 2019 Tommy Bojanin. All rights reserved.
//

#include "MyRectangle.h"

MyRectangle::MyRectangle(int x, int y, int width, int height, color col): x(x), y(y), width(width), height(height), shapeColor(col) {}

int MyRectangle::getX() {
    return this->x;
}

MyRectangle::~MyRectangle() {
    
}

// Accessors
int MyRectangle::getHeight() {
    return this->height;
}

int MyRectangle::getY() {
    return this->y;
}

color MyRectangle::getColor() {
    return this->shapeColor;
}

int MyRectangle::getWidth() {
    return this->width;
}

// Mutators

void MyRectangle::setX(int x) {
    this->x = x;
}

void MyRectangle::setY(int y) {
    this->y = y;
}

void MyRectangle::setWidth(int width) {
    this->width = width;
}

void MyRectangle::setHeight(int height) {
    this->height = height;
}

void MyRectangle::setColor(color col) {
    this->shapeColor = col;
}

void MyRectangle::draw(FrameBuffer &buff) {
    std::cout << "drawn  buffer\n";
    for (int drawnYPixels = y; drawnYPixels<  y + height; drawnYPixels++) {
        for(int drawnXPixels = x; drawnXPixels < x + width; drawnXPixels++) {
            buff.setPixel(drawnXPixels, drawnYPixels, shapeColor);
        }
    }
}


