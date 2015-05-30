#pragma once

#include <map>
using namespace std;

class TestSets
{
public:
	TestSets(void);
	virtual ~TestSets(void);

	// <will>
	// Adds the given set to the internal map. Will not replace a set with equal length 
	// already in the map. Returns true if the operation is successful, and false otherwise. 
	// If there is already a set with the given length in the map, returns false.
	bool addSet(int* set, int length);

	// <will>
	// Gets the set with the given length from the map
	int* getSet(int length);

private:
	// <will>
	// sets is a map whose keys are set lengths and whose values are the sets themselves.
	// This implementation was chosen so that we only have one set for each given length.
	// Also, we can chose any collection of lengths and only have keys for those lengths.
	map<int, int*>* sets;
};

