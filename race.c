#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};
// Print functions section
void printIntro() {
  printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");
}
void printCountDown() {
  printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRace!\n");
}
void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %i\nFirst Place Is: %s in the %s race car!\n",race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}
void printCongratulations(struct Race race) {
  printf("After the final lap we have a winner!\nLet's all congratulate %s in the %s race car for an amazing performance.\nIt was truly a great race and everybody have a goodnight!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}
// Logic functions section
int calculateTimeToCompleteLap() {
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;

  return (nerves + acceleration + speed);
}
void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
  }
  else {
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;    
  }
}
void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, "", ""};
  for(int i = 1; i < race.numberOfLaps; i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    struct Race* racePointer = &race;
    updateFirstPlace(racePointer, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap += 1;
  }
  printCongratulations(race);
}


int main(void) {
	srand(time(0));
  struct RaceCar raceCar1 = {"Guy", "Yellow", 0};
  struct RaceCar raceCar2 = {"Buddy", "Green", 0};
  printIntro();
  printCountDown();
  struct RaceCar* raceCar1Pointer = &raceCar1;
  struct RaceCar* raceCar2Pointer = &raceCar2;
  startRace(raceCar1Pointer, raceCar2Pointer);
};
