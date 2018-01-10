/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Polygon.h"


Polygon::Polygon (string _name, string _colour, float _xcen, float _ycen, t_point vertices[100], int _numVertices)
:Shape(_name, _colour, _xcen, _ycen)
{
    for (int i = 0; i < 100; i++) {
      relVertex[i].x = vertices[i].x;
      relVertex[i].y = vertices[i].y;
   }
    
    numVertices = _numVertices;
}
   
Polygon::~Polygon()
{}
//count vertices later
void Polygon::print () const 
{
    Shape::print();
    cout << "polygon";
    for (int i = 0; i < numVertices; i++) {
        cout << " (" << getXcen() + relVertex[i].x << "," 
                << getYcen() + relVertex[i].y << ")";
    }
    cout << endl;

}

void Polygon::scale (float scaleFac) 
{
    for (int i = 0; i < numVertices; i++) {
          relVertex[i].x *= scaleFac;
          relVertex[i].y *= scaleFac;
       }
}

float Polygon::computeArea () const 
{


  float area = 0;         // Accumulates area in the loop
  int j = numVertices-1;  // The last vertex is the 'previous' one to the first

  for (int i = 0; i < numVertices; i++)
    { area = area +  (relVertex[j].x + relVertex[i].x) * (relVertex[j].y - relVertex[i].y); 
      j = i;  //j is previous vertex to i
    }
  
  return area/2;


}

float Polygon::computePerimeter () const 
{
    float length = 0;
    float perimeter = 0;
    int i = 0;
        
    while(i != numVertices-1){
        //determine the length between two vertices
        length = sqrt(pow(relVertex[i].x - relVertex[i+1].x, 2) + pow(relVertex[i].y - relVertex[i+1].y, 2)); 
        perimeter += length;
        i++;  
    }
    length = sqrt(pow(relVertex[numVertices-1].x - relVertex[0].x, 2) + pow(relVertex[numVertices-1].y - relVertex[0].y, 2)); 
    perimeter += length;
    
    return perimeter;

}

void Polygon::draw (easygl* window) const 
{
    t_point coords[numVertices];
    
    for (int i = 0; i < numVertices; i++) {
     coords[i].x = getXcen() + relVertex[i].x;
     coords[i].y = getYcen() + relVertex[i].y;
   }
   window->gl_setcolor(getColour());
   window->gl_fillpoly(coords, numVertices);
}

bool Polygon::pointInside (float x, float y) const 
{
    t_point click;
    click.x = x - getXcen();
    click.y = y - getYcen();
    
   t_point vecOfSide;
   float distanceAlongVector, yDistance;
   int endIndex;
   int sidesToLeft = 0;
   
   for (int istart = 0; istart < numVertices; istart++) {
      endIndex = (istart + 1) % numVertices; // Next vertex after istart
      vecOfSide = getVecBetweenPoints (relVertex[istart], relVertex[endIndex]);
      yDistance = (click.y - relVertex[istart].y);
      if (vecOfSide.y != 0) {
          distanceAlongVector = yDistance / vecOfSide.y;
      }
      else if (yDistance == 0) {
          distanceAlongVector = 0;
      }
      else {
          distanceAlongVector = 1e10; // Really infinity, but this is big enough
      }
      
      // We intersect this side if the distance (scaling) along the side vector to 
      // get to our "click" y point is between 0 and 1.  Count the first 
      // endpoint of the side as being part of the line (distanceAlongVector = 0)
      // but don't count the second endPoint; we'll intersect that point later 
      // when we check the next side.
      if (distanceAlongVector >= 0 && distanceAlongVector < 1) {
         float xIntersection = relVertex[istart].x + vecOfSide.x * distanceAlongVector;
         if (xIntersection <= click.x ) 
             sidesToLeft++;
      }
   }
   
   return (sidesToLeft == 1);
}

t_point Polygon::getVecBetweenPoints (t_point start, t_point end) const {
   t_point vec;
   vec.x = end.x - start.x;
   vec.y = end.y - start.y;
   return (vec);
}
