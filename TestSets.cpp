#include "stdafx.h"
#include "TestSets.h"

#include <map>
using namespace std;


TestSets::TestSets(void)
{
	// <will>
	// Dynamically allocate a new map
	sets = new map<int, int*>;
}


TestSets::~TestSets(void)
{
	// <will>
	// Delete everything in the map
	for (map<int, int*>::iterator it = sets->begin(); it != sets->end(); it++)
	{
		delete it->second;
		it->second = 0;
	}

	// <will>
	// Delete the map itself
	delete sets;
	sets = 0;
}

bool TestSets::addSet(int* set, int length)
{
	// <will>
	// If there is no set for this length already in the map, add the new set to the map
	if (getSet(length) == 0)
	{
		(*sets)[length] = set;
		return true;
	}

	return false;
}

int* TestSets::getSet(int length)
{
	// <will>
	// Find the iterator for the element in the map with the given key (length)
	map<int, int*>::iterator it = sets->find(length);

	// <will>
	// If the iterator is equal to sets->end, then the key is not present in the map, so
	// return NULL
	if (it == sets->end())
	{
		return 0;
	}

	return it->second;
}
