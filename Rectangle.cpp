/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Rectangle.h"


Rectangle::Rectangle(string _name, string _colour, float _xcen, float _ycen, float _width, float _height)
:Shape(_name, _colour, _xcen, _ycen), width(_width), height(_height)
{}
        
Rectangle::~Rectangle()
{}

void Rectangle::print() const
{
   Shape::print();
   cout.precision(1);
   cout.setf(ios::fixed);
   cout << "rectangle width: " << width << " height: " << height << endl;

}

void Rectangle::scale (float scaleFac)
{
    width *= scaleFac;
    height *= scaleFac;
}

float Rectangle::computeArea() const
{
    float area = width * height;
    return area;
}

float Rectangle::computePerimeter() const
{
    float perimeter = 0;
    
    perimeter = 2* (width + height);
    
    return perimeter;
}

void Rectangle::draw(easygl* window) const
{
    window->gl_setcolor(getColour());
    window->gl_fillrect(getXcen() - width/2, getYcen() - height/2, getXcen() + width/2, getYcen() + height/2);
}

bool Rectangle::pointInside(float x, float y) const
{
    float _xcen = getXcen();
    float _ycen = getYcen();
    
    if((x > (_xcen - width/2)) && (x < (_xcen + width/2)) &&  (y > (_ycen - height/2)) && (y < (_ycen + height/2)))
        return true;  
    else
        return false;
}