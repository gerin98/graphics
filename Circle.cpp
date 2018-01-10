/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Circle.h"

Circle::Circle(string _name, string _colour, float _xcen, float _ycen, float _radius)
:Shape(_name, _colour, _xcen, _ycen), radius(_radius)
{}
        
Circle::~Circle()
{}

void Circle::print() const 
{
    Shape::print();
    cout.precision(1);
    cout.setf(ios::fixed);
    cout << "circle radius: " << radius << endl;
}

void Circle::scale (float scaleFac) 
{
    radius *= scaleFac;
}

float Circle::computeArea() const 
{
    float area = PI*radius*radius;
    return area;
}

float Circle::computePerimeter() const 
{
    float perimeter = 2 * PI * radius;
    return perimeter;
}

void Circle::draw(easygl* window) const 
{
    window->gl_setcolor(getColour());
    window->gl_fillarc(getXcen(), getYcen(), radius, 0, 360);
}

bool Circle::pointInside(float x, float y) const 
{
    float _xcen = getXcen();
    float _ycen = getYcen();

    
    //radius >= sqrt(pow(_ycen - y, 2.0) + pow(_xcen - x, 2.0));
    
    if(radius >= sqrt(pow(_ycen - y, 2.0) + pow(_xcen - x, 2.0)))    
        return true;
    else
        return false;
}