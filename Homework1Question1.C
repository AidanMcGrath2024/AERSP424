#include <stdio.h>

int main() {
  //Plane Limitations
  int maxallowablegrossweight = 2950; //pounds
  int forwardCGlimit = 82.1; //inches
  int aftCGlimit = 84.7; //inches 

  //Airplane Empty Weight User Input
  printf("What is the empty weight of the airplane? Type the weight in pounds and press enter: \n");
  int emptyweight;
  scanf("%d", &emptyweight);

  //Airplane Empty Weight Moment User Input
  printf("What is the empty weight moment of the airplane? Type the weight in pounds-inches and press enter: \n");
  int emptyweightmoment;
  scanf("%d", &emptyweightmoment);
  
  //Front Seat Occupant Total Weight User Input
  printf("How many passengers will be flying in the front? Type the number of passangers and press enter: \n");
  int frontseatoccupants;
  scanf("%d", &frontseatoccupants);
  int weightfrontseatoccupants = 0;
  for (int frontpassengerindex = 0; frontpassengerindex < (frontseatoccupants+1); frontpassengerindex++)
  {
    int weightoffrontseatoccupant;
    printf("What is the weight of passenger %d in the front? Type the weight of passanger in pounds and press enter: \n",frontpassengerindex);
    scanf("%d", &weightoffrontseatoccupant);
    weightfrontseatoccupants = weightfrontseatoccupants + weightoffrontseatoccupant;
  }

  //Front Seat Moment Arm User Input
  printf("What is the front seat moment arm? Type the length in inches and press enter: \n");
  int frontseatmomentarm;
  scanf("%d", &frontseatmomentarm);

  //Rear Seat Occupant Total Weight User Input
  printf("How many passengers will be flying in the rear? Type the number of passangers and press enter: \n");
  int rearseatoccupants;
  scanf("%d", &rearseatoccupants);
  int weightrearseatoccupants = 0;
  for (int rearpassengerindex = 0; rearpassengerindex < (rearseatoccupants+1); rearpassengerindex++)
  {
    int weightofrearseatoccupant;
    printf("What is the weight of passenger %d in the rear? Type the weight of passanger in pounds and press enter: \n",rearpassengerindex);
    scanf("%d", &weightofrearseatoccupant);
    weightrearseatoccupants = weightrearseatoccupants + weightofrearseatoccupant;
  }

  //Rear Seat Moment Arm User Input
  printf("What is the front seat moment arm? Type the length in inches and press enter: \n");
  int rearseatmomentarm;
  scanf("%d", &rearseatmomentarm);

  //Gallons of Fuel User Input
  printf("How many gallons of fuel is usable? Type the volume of fuel in gallons and press enter: \n");
  int usablefuel;
  scanf("%d", &usablefuel);

  //Usable Fuel Weight per Gallon User Input
  printf("What is the weight per gallon of the usable fuel? Type the conversion in pounds per gallon and press enter: \n");
  int fuelweightpergallon;
  scanf("%d", &fuelweightpergallon);

  //Fuel Tank Moment Arm User Input
  printf("What is the fuel tank's moment arm? Type the length in inches and press enter: \n");
  int fueltankmomentarm;
  scanf("%d", &fueltankmomentarm);

  //Baggage Weight User Input
  printf("What is the total baggage weight? Type the weight in pounds and press enter: \n");
  int baggageweight;
  scanf("%d", &baggageweight);

  //Baggage Moment Arm User Input
  printf("What is the baggage weight's moment arm? Type the length in inches and press enter: \n");
  int baggagemomentarm;
  scanf("%d", &baggagemomentarm);

  int grossweight = emptyweight + weightfrontseatoccupants + weightrearseatoccupants + (usablefuel*fuelweightpergallon) + baggageweight;
  float centerofgravity = ((emptyweight*emptyweightmoment) + (frontseatmomentarm*weightfrontseatoccupants) + (rearseatmomentarm*weightrearseatoccupants) + (fueltankmomentarm*usablefuel*fuelweightpergallon) + (baggagemomentarm*baggageweight))/(grossweight);
  if (centerofgravity < forwardCGlimit)
  {
    double newusablefuel = (((emptyweight*emptyweightmoment) + (frontseatmomentarm*weightfrontseatoccupants) + (rearseatmomentarm*weightrearseatoccupants) + (baggagemomentarm*baggageweight)) - (aftCGlimit * (emptyweight + weightfrontseatoccupants + weightrearseatoccupants + baggageweight)))/(aftCGlimit*fuelweightpergallon - fueltankmomentarm*fuelweightpergallon);
    grossweight = emptyweight + weightfrontseatoccupants + weightrearseatoccupants + (newusablefuel*fuelweightpergallon) + baggageweight;
    double centerofgravity = ((emptyweight*emptyweightmoment) + (frontseatmomentarm*weightfrontseatoccupants) + (rearseatmomentarm*weightrearseatoccupants) + (fueltankmomentarm*newusablefuel*fuelweightpergallon) + (baggagemomentarm*baggageweight))/(grossweight);
    double drainedfuel = (newusablefuel-usablefuel)*fuelweightpergallon;
    double precdrainedfuel = round(drainedfuel*100)/100;
    if (grossweight > maxallowablegrossweight)
    {
      printf("Your loading is not within the aircraft's tolerances!\n");
    }
    else
    {
      printf("The amount of fuel drained is %f gallons. \n", (precdrainedfuel));
      printf("The new gross weight of the aircraft is: %f pounds.\n",grossweight);
      printf("The new center of gravity of the aircraft is: %f inches from the engine's firewall.\n",centerofgravity);
    }
  }
  else if (centerofgravity > aftCGlimit)
  {
    double newusablefuel = (((emptyweight*emptyweightmoment) + (frontseatmomentarm*weightfrontseatoccupants) + (rearseatmomentarm*weightrearseatoccupants) + (baggagemomentarm*baggageweight)) - (aftCGlimit * (emptyweight + weightfrontseatoccupants + weightrearseatoccupants + baggageweight)))/(aftCGlimit*fuelweightpergallon - fueltankmomentarm*fuelweightpergallon);
    grossweight = emptyweight + weightfrontseatoccupants + weightrearseatoccupants + (newusablefuel*fuelweightpergallon) + baggageweight;
    double centerofgravity = ((emptyweight*emptyweightmoment) + (frontseatmomentarm*weightfrontseatoccupants) + (rearseatmomentarm*weightrearseatoccupants) + (fueltankmomentarm*newusablefuel*fuelweightpergallon) + (baggagemomentarm*baggageweight))/(grossweight);
    double addedfuel = (newusablefuel-usablefuel)*fuelweightpergallon;
    double precaddedfuel = round(addedfuel*100)/100;
    if (grossweight > maxallowablegrossweight)
    {
      printf("Your loading is not within the aircraft's tolerances!\n");
    }
    else
    {
      printf("The amount of fuel added is %f pounds. \n", (precaddedfuel));
      printf("The new gross weight of the aircraft is: %f pounds.\n",grossweight);
      printf("The new center of gravity of the aircraft is: %f inches from the engine's firewall.\n",centerofgravity);
    }
  }
  else 
  {
    printf("The gross weight of the aircraft is %f pounds.\n", grossweight);
    printf("Fuel amount was not adjusted, the center of gravity is within the aircraft's limits: %f inches from the engine's firewall.\n", centerofgravity);
  }
  /*
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
  */
  return 0;
}
