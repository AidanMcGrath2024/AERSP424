#include <stdio.h>

int main() {
  /**/
  //Plane Limitations
  int maxallowablegrossweight = 2950; //pounds
  int forwardCGlimit = 82.1; //inches
  int aftCGlimit = 84.7; //inches 

  //Airplane Empty Weight User Input
  printf("What is the empty weight of the airplane? Type the weight in pounds and press enter: \n");
  int emptyweight;
  scanf("%i", &emptyweight);

  //Airplane Empty Weight Moment User Input
  printf("What is the empty weight moment of the airplane? Type the weight in pounds-inches and press enter: \n");
  int emptyweightmoment;
  scanf("%i", &emptyweightmoment);
  
  //Front Seat Occupant Total and Weight User Inputs
  printf("How many passengers will be flying in the front? Type the number of passangers and press enter: \n");
  int frontseatoccupants;
  scanf("%i", &frontseatoccupants);
  int frontseatoccupantsweightarray[frontseatoccupants];
  for (int frontpassengerindex = 0; frontpassengerindex < (frontseatoccupants+1); frontpassengerindex++)
  {
    int weightoffrontseatoccupant;
    printf("What is the weight of passenger %i in the front? Type the weight of passanger in pounds and press enter: \n",frontpassengerindex);
    scanf("%i", &weightoffrontseatoccupant);
    frontseatoccupantsweightarray[frontpassengerindex] = weightoffrontseatoccupant;
  }

  //Front Seat Moment Arm User Input
  printf("What is the front seat moment arm? Type the length in inches and press enter: \n");
  int frontseatmomentarm;
  scanf("%i", &frontseatmomentarm);

  //Rear Seat Occupant Total and Weight User Inputs
  printf("How many passengers will be flying in the rear? Type the number of passangers and press enter: \n");
  int rearseatoccupants;
  scanf("%i", &rearseatoccupants);
  int rearseatoccupantsweightarray[rearseatoccupants];
  for (int rearpassengerindex = 0; rearpassengerindex < (rearseatoccupants+1); rearpassengerindex++)
  {
    int weightofrearseatoccupant;
    printf("What is the weight of passenger %i in the rear? Type the weight of passanger in pounds and press enter: \n",rearpassengerindex);
    scanf("%i", &weightofrearseatoccupant);
    rearseatoccupantsweightarray[rearpassengerindex] = weightofrearseatoccupant;
  }

  //Rear Seat Moment Arm User Input
  printf("What is the front seat moment arm? Type the length in inches and press enter: \n");
  int rearseatmomentarm;
  scanf("%i", &rearseatmomentarm);

  //Gallons of Fuel User Input
  printf("How many gallons of fuel is usable? Type the volume of fuel in gallons and press enter: \n");
  int usablefuel;
  scanf("%i", &usablefuel);

  //Usable Fuel Weight per Gallon User Input
  printf("What is the weight per gallon of the usable fuel? Type the conversion in pounds per gallon and press enter: \n");
  int fuelweightpergallon;
  scanf("%i", &fuelweightpergallon);

  //Fuel Tank Moment Arm User Input
  printf("What is the fuel tank's moment arm? Type the length in inches and press enter: \n");
  int fueltankmomentarm;
  scanf("%i", &fueltankmomentarm);

  //Baggage Weight User Input
  printf("What is the total baggage weight? Type the weight in pounds and press enter: \n");
  int baggageweight;
  scanf("%i", &baggageweight);

  //Baggage Moment Arm User Input
  printf("What is the baggage weight's moment arm? Type the length in inches and press enter: \n");
  int baggagemomentarm;
  scanf("%i", &baggagemomentarm);

  int emptyweight = 2050; //pounds
  int emptyweightmoment = 155400; //pound*inches
  int frontseatoccupants = 2; 
  int weightfrontseatoccupants = 180, 150; //pounds
  int frontseatmomentarm = 85; //inches 
  int rearseatoccupants = 2;
  int weightrearseatoccupants = 160, 170; //pounds
  int rearseatmomentarm = 121; //inches 
  int usablefuel = 44; //gallons
  int fuelweightpergallon = 6; //pounds
  int fueltankmomentarm = 75; //inches
  int baggageweight = 10; //pounds
  int baggagemomentarm = 140; //inches
  int grossweight = emptyweight + weightfrontseatoccupants + weightrearseatoccupants + (usablefuel*fuelweightpergallon) + baggageweight;
  int maxallowablegrossweight = 2950; //pounds
  int forwardCGlimit = 82.1; //inches
  int aftCGlimit = 84.7; //inches 
  if (grossweight < maxallowablegrossweight)
  {
    usablefuel = maxallowablegrossweight - grossweight; //pounds
    printf("The new gross weight of the aircraft is: %f pounds",grossweight);


  }
  return 0;
}
