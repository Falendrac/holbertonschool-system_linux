#ifndef LAPS_H
#define LAPS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct carRace - Struct needed to be in static array
 *
 * @carId: Id of the car that entered in the race
 * @carTour: Number of tour of the car
*/
typedef struct carRace
{
	int carId;
	int carTour;
} carRace;

void race_state(int *id, size_t size);
carRace *_allocateCountTour(int *id, size_t size, carRace *countTour);
void _printRaceTour(carRace *countTour, size_t sizeCountTour);
int _carTourAdd(carRace *countTour, size_t sizeTour, int *id, size_t size);
void _sortRaceArray(size_t size, carRace *countTour);

#endif
