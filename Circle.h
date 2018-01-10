/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: amalaraj
 *
 * Created on December 5, 2017, 1:57 AM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "easygl.h"

class Circle : public Shape {
    private:
        float radius;
    public:
        Circle(string _name, string _colour, float _xcen, float _ycen, float _radius);
        
        virtual ~Circle();
      
        virtual void print() const override;
        
        virtual void scale (float scaleFac) override;
        
        virtual float computeArea() const override;
        
        virtual float computePerimeter() const override;
        
        virtual void draw(easygl* window) const override;
        
        virtual bool pointInside(float x, float y) const override;
    
    
    
};

#endif /* CIRCLE_H */

