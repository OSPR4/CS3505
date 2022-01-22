/*
CS3505: A1: An Ecological Simulation
Author: Osee Pierre
Description: This program models a predator-prey (rabbit and fox) 
relationship using the Lotka-Volterra equation with environmental carrying-capacity. 
It computes the rabbit and fox populations and displays them as a vertical ASCII chart, 
with each row showing the current rabbit and fox population as time progresses.
*/
#include <iostream>
#include <math.h> 

//Forward  declaration of methods used in this program
void runSimulation(int, double, double);
void updatePopulations(double, double, double, double, double, double&, double&);
void plotCharacter(int, char);
void plotPopulations(double, double, double);
void incrementCounter(int*);


/*
The main function asks users for initial rabbit and fox populations, 
stored as doubles to smooth the simulation, then calls runSimulation with a value 
of 500 iterations and the initial rabbit and fox populations. If the user enters anything 
that cannot be converted to a double for an initial population, it displays an error message 
and terminates the program. 
*/
int main()
{
    double rabbitPopulation;
    double foxPopulation;

    std::cout << "Enter rabbit population: ";
    if(!(std::cin >> rabbitPopulation))
    {
        std::cout << "Unable to parse input into double" << std::endl;
        return -1;
    }

    std::cout << "Enter fox population: ";
    if(!(std::cin >> foxPopulation))
    {
        std::cout << "Unable to parse input into double" << std::endl;
        return -1;
    }

    runSimulation(500, rabbitPopulation, foxPopulation);
}

/*
The runSimulation function sets the parameters needed for the update 
equation, and run the simulation for iterations steps or
until the predator or prey population goes below 1.
*/
void runSimulation(int interations, double numRabbits, double numFoxes)
{
    //Values that are used in the Lotka-Volterra equation
    double rabbitGrowth = 0.2, predationRate = 0.0022, foxPreyConversion = 0.6, 
           foxMortalityRate = 0.2, carryCapacity = 1000.0;

    int counter = 0;

    //Print the initiall population of rabbits and foxes
    //If initial populations are below one, the print process will clamp it to 0
    plotPopulations(numRabbits, numFoxes, 0.1);
    std::cout << "\n";

    while(counter < interations && (numRabbits >= 1 && numFoxes >= 1))
    {
        updatePopulations(rabbitGrowth, predationRate, foxPreyConversion, foxMortalityRate, 
                          carryCapacity, numRabbits, numFoxes);
        incrementCounter(&counter);
         std::cout << "\n";
    }
  
}

/*
The updatePopulations function takes in the model parameters, the number of rabbits and number of foxes, then
calculates the change in rabbit and fox populations and uses the plotPopulations function to begin to 
process of drawing the output.
*/
void updatePopulations(double g, double p, double c, double m, double K, 
                       double& numRabbits, double& numFoxes)
{
    double scaleFactor = 0.1;
    double R = numRabbits;
    double F = numFoxes;

    double deltaRabbits = g*R*(1-(R/K)) - (p*R*F);
    double deltaFoxes = (c*p*R*F) - (m*F);

    numRabbits += deltaRabbits;
    numFoxes += deltaFoxes;
    plotPopulations(numRabbits, numFoxes, scaleFactor);
}

/*
The plotPopulations function takes in the number of rabbits, the number of foxes, 
and a fractional scale factor and uses the plotCharacter function to draw a row 
of a text chart with an 'F' for foxes and 'r' for rabbits and '*' if the drawing of each would overlap. 
The characters are drawn in position floor(num*scaleFactor) from the left margin (with the first space being position 0).
*/
void plotPopulations(double numRabbits, double numFoxes, double scaleFactor)
{
    int scaled_numRabbits = (int)floor(numRabbits * scaleFactor);
    int scaled_numFoxes = (int)floor(numFoxes * scaleFactor);

    if(scaled_numRabbits == scaled_numFoxes)
    {
        plotCharacter(scaled_numRabbits, '*');
    }
    else if(scaled_numRabbits > scaled_numFoxes)
    {
        plotCharacter(scaled_numFoxes, 'F');

        //Calculates the adjustment needed to print the rabbits population on the same line with the foxes population
        scaled_numRabbits = scaled_numRabbits - scaled_numFoxes - 1;

        plotCharacter(scaled_numRabbits, 'r');
 
    }
    else
    {
        plotCharacter(scaled_numRabbits, 'r');

        //Calculates the adjustment needed to print the foxes population on the same line with the rabbits population
        scaled_numFoxes = scaled_numFoxes-scaled_numRabbits - 1;        
        
        plotCharacter(scaled_numFoxes, 'F');

    }

}

/*
The plotCharacter function takes in an int number and a character and sends to std::cout a certain amount spaces 
followed by the character. If the number parameter is less than 1, it just outputs the character.
*/
void plotCharacter(int plotNumber, char plotCharacter)
{
    
    for (int i = 0; i < plotNumber; i++)
    {
        std::cout << " ";
    }
    
    std::cout << plotCharacter;
}


/*
The incrementCounter function takes a pointer to an integer parameter add 1 to the value pointed to by the pointer. 
This function is used to update the iteration count in the main simulation loop. 
*/
void incrementCounter(int *counter)
{
    *counter = *counter + 1;
}
          