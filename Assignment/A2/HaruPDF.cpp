/*
CS3505: A2: Classes, Facades, and Makefiles
Author: Osee Pierre
Description: This class serves as a facade to Haru
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "HaruPDF.h"


//Setup PDF
HaruPDF::HaruPDF(char filename[256])
{
    strcpy (fname, filename);
    strcat (fname, ".pdf");

    pdf = HPDF_New (NULL, NULL);
    /* add a new page object. */
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);

    HPDF_Page_BeginText (page);
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 20);
}

//Add text to page base on text text position
void HaruPDF::AddTextToPage(char text, double angle, double x, double y)
{

        characterBuffer[0] = text;
        characterBuffer[1] = 0;

        double radAngle = angle / 180 * M_PI;

        // This function defines where any following text will be placed
        // on the page. The cos/sin stuff is actually defining a 2D rotation
        // matrix.
        HPDF_Page_SetTextMatrix(page, cos(radAngle), sin(radAngle), -sin(radAngle), cos(radAngle),x, y);

        HPDF_Page_ShowText (page, characterBuffer);
  
           
}

//Close and save PDF
void HaruPDF::SavePDF()
{
    HPDF_Page_EndText (page);

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);

}
