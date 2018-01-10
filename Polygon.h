/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Polygon.h
 * Author: amalaraj
 *
 * Created on December 5, 2017, 3:04 AM
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include "easygl.h"

class Polygon : public Shape {
private:
    t_point relVertex[100];
    int numVertices;
public:
   Polygon (string _name, string _colour, float _xcen, float _ycen, t_point vertices[100], int _numVertices);
   
   virtual ~Polygon();

   
   virtual void print () const override;
   
   virtual void scale (float scaleFac) override;
   
   virtual float computeArea () const override;
   
   virtual float computePerimeter () const override;
   
   virtual void draw (easygl* window) const override;
   
   virtual bool pointInside (float x, float y) const override;
   
   
   t_point getVecBetweenPoints (t_point start, t_point end) const;
};


#endif /* POLYGON_H */

