/*
CS3505: A2: Classes, Facades, and Makefiles
Author: Osee Pierre
Description: Header file for HaruPDF
*/
#include "hpdf.h"

#ifndef HARUPDF_H
#define HARUPDF_H
class HaruPDF
{
    private:
        HPDF_Doc  pdf;
        HPDF_Page page;
        char fname[256];
        HPDF_Font font;
        char characterBuffer[2];
    public:
        HaruPDF(char filename[256]);
        void AddTextToPage(char text, double angle, double x, double y);
        void SavePDF();
};
#endif