/*
CS3505: A2: Classes, Facades, and Makefiles
Author: Osee Pierre
Description: Header file for Spiral
*/
#include "HaruPDF.h"

#ifndef SPIRAL_H
#define SPIRAL_H
class Spiral
{
    private:
        double centerX;
        double centerY;
        double angle; 
        double radius;
        double letterAngle; 
        double x;
        double y;
        double radLetterPosition; 
       
    public:
        Spiral(double _centerX, double _centerY, double _startingAngle, double _radius);
        double getTextX();
        double getTextY();
        double getLetterAngle();
        void SpiralText();
        Spiral& operator++();
        Spiral operator++(int);
};
#endif