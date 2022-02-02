/*
CS3505: A2: Classes, Facades, and Makefiles
Author: Osee Pierre
Description: This class implements the spiral functionality
*/
#include <math.h>
#include <iostream>
#include "Spiral.h"


//Spiral class constructor
Spiral::Spiral(double _centerX, double _centerY, double _startingAngle, double _radius)
{
    centerX = _centerX;
    centerY = _centerY;
    angle = _startingAngle;
    radius = _radius;
}

void Spiral::SpiralText()
{
        // letterAngle determines the angle of the letter on the page. radLetterPosition is how far

        letterAngle = (angle-90);
        radLetterPosition = (angle) / 180 * M_PI;

        // The position of the character depends on the center point
        // plus the angle and the radius.
        x = centerX + cos(radLetterPosition) * radius;
        y = centerY + sin(radLetterPosition) * radius;
        
        radius++;

        angle -= 900/radius; // change the angle around the circle
}

//Returns x position of text
double Spiral::getTextX()
{
    return x;
}
//Returns y position of text
double Spiral::getTextY()
{
    return y;
}
//Return the angle of the text
double Spiral::getLetterAngle()
{

    return letterAngle;
}

 Spiral& Spiral::operator++()
 {
     this->SpiralText();
     return *this;
 }
 Spiral Spiral::operator++(int)
{
    Spiral spiral(*this);
    ++(*this);
    return spiral;
}
