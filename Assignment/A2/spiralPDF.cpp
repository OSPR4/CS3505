/*
CS3505: A2: Classes, Facades, and Makefiles
Author: Osee Pierre
Description: This program utilizes HaruPDF and Spiral to print text in a spiral on a PDF
*/

#include <iostream>
#include <string.h>
#include "HaruPDF.h"
#include "Spiral.h"

int main(int argc, char **argv)
{
    char fileName[256];
     char text[256];

    strcpy (fileName, argv[0]);
   
   //Checks for input text before processing
   if(argc < 2)
   {
      std::cout << "Requires input text" << std::endl;
      return 1;
   }
   else
   {
       strcpy (text, argv[1]);

   }
   
    HaruPDF myPDF(fileName);
    Spiral mySpiral(210,300, 180, 40);

    for (size_t i = 0; i < strlen (text); i++) {

       mySpiral++;
       myPDF.AddTextToPage(text[i], mySpiral.getLetterAngle(), mySpiral.getTextX(), mySpiral.getTextY());
        
    }

     myPDF.SavePDF();

     return 0;
}