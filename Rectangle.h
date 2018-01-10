/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rectangle.h
 * Author: amalaraj
 *
 * Created on December 5, 2017, 12:26 AM
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "easygl.h"

class Rectangle : public Shape {
    private:
        float width;
        float height;
    public:
        Rectangle(string _name, string _colour, float _xcen, float _ycen, float _width, float _height);
        
        virtual ~Rectangle();
      
        virtual void print() const override;
        
        virtual void scale (float scaleFac) override;
        
        virtual float computeArea() const override;
        
        virtual float computePerimeter() const override;
        
        virtual void draw(easygl* window) const override;
        
        virtual bool pointInside(float x, float y) const override;
    
    
    
};

#endif /* RECTANGLE_H */

