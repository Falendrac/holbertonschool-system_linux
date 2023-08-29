#include "laps.h"

/**
 * allocateCountTour - Allocate the pointer countTour with the new size
 *
 * @id: The array of identifier car
 * @size: Size of the array
 * @countTour: The pointer of the number of tour
 *
 * Return: The new pointer carRace
*/
carRace *_allocateCountTour(int *id, size_t size, carRace *countTour)
{
	static size_t indexCountTour;
	static size_t indexInit;
	size_t indexId = 0;

	countTour = realloc(countTour, size * sizeof(struct carRace));
	for (; indexInit < size; indexInit++)
	{
		countTour[indexInit].carId = 0;
		countTour[indexInit].carTour = 0;
	}

	for (; indexCountTour < size; indexCountTour++)
	{
		if (!countTour[indexCountTour].carId)
		{
			countTour[indexCountTour].carId = id[indexId];
			printf("Car %d joined the race\n", id[indexId]);
			countTour[indexCountTour].carTour = 0;
			indexId++;
		}
	}

	_sortRaceArray(size, countTour);

	return (countTour);
}

/**
 * _sortRaceArray - Sort the array countTour
 *
 * @size: Size of the array
 * @countTour: The pointer of the number of tour
*/
void _sortRaceArray(size_t size, carRace *countTour)
{
	size_t index, sortIndex, lastIndex = size - 1;
	carRace tmp;

	for (index = 0; index < lastIndex; index++)
	{
		if (countTour[index].carId > countTour[lastIndex].carId)
		{
			for (sortIndex = index; sortIndex < size; sortIndex++)
			{
				tmp = countTour[sortIndex];
				countTour[sortIndex] = countTour[lastIndex];
				countTour[lastIndex] = tmp;
			}
		}
	}
}

/**
 * _carTourAdd - Add laps for the cars passes in argument
 *
 * @countTour: The array of all cars in the race
 * @sizeCountTour: The size of the array countTour
 * @id: The identifier we want to add a laps
 *
 * Return: 0 if cars identifier is not in the race tour,
 * 1 if the laps is correctly added to all cars
*/
int _carTourAdd(carRace *countTour, size_t sizeCountTour, int id)
{
	size_t index = 0;

	while (index < sizeCountTour)
	{
		if (countTour[index].carId == id)
		{
			countTour[index].carTour++;
			return (1);
		}

		index++;
	}

	return (0);
}

/**
 * _printRaceTour - Print all the laps of all car in the Race Tour
 *
 * @countTour: The array of all cars in the race
 * @sizeCountTour: The size of the array countTour
*/
void _printRaceTour(carRace *countTour, size_t sizeCountTour)
{
	size_t index;

	printf("Race state:\n");
	for (index = 0; index < sizeCountTour; index++)
	{
		printf("Car %d [%d laps]\n",
				countTour[index].carId, countTour[index].carTour);
	}
}

/**
 * race_state - Count the number of tour of each car that entered
 * the race
 *
 * @id: The array of identifier car
 * @size: Size of the array
*/
void race_state(int *id, size_t size)
{
	static carRace *countTour;
	static size_t sizeCountTour;
	size_t indexId;

	if (!id)
	{
		if (countTour)
			free(countTour);
		return;
	}

	if (!countTour)
		countTour = _allocateCountTour(id, sizeCountTour += size, countTour);
	else
	{
		for (indexId = 0; indexId < size; indexId++)
			if (_carTourAdd(countTour, sizeCountTour, id[indexId]) == 0)
				countTour = _allocateCountTour(id + indexId,
												sizeCountTour += 1, countTour);
	}

	_printRaceTour(countTour, sizeCountTour);
}
