// SetEfficiency.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>

#include "Sorter.h"

using namespace std;

// utility methods
vector<int>* generateShuffledSet(int length);
vector<clock_t> testSorts(vector<int>* set);
vector<clock_t> testIsUniques(vector<int>* set);

// typedefs (for function pointers)
typedef bool (*isUnique)(vector<int>*, int, int);
typedef vector<int>* (*soringAlgorithm)(vector<int>*);

// <will>
// Struct for IsUnique methods
struct IsUniqueMethod
{
	bool functionLongerThanMax;
	isUnique function;
};

int main()
{
	// <will>
	// Code to test the various algorithms. Change testAlgorithms to false if not desired
	bool testSortAlgorithms = false;
	if (testSortAlgorithms)
	{
		// <will>
		// Test the sorts with a shuffled set.
		// The order of timings in the vector is bubble, insertion, merge.
		int length = 10000;
		vector<int>* testSet = generateShuffledSet(length);
		vector<clock_t> results = testSorts(testSet);
		cout << "bubble: " << results[0] << endl;
		cout << "insertion: " << results[1] << endl;
		cout << "merge: " << results[2] << endl;
		return 0;
	}

	bool testIsUniqueAlgorithms = false;
	if (testIsUniqueAlgorithms)
	{
		// <will>
		// Test the IsUnique algorithms. Can be tested when the set is and is not sorted
		int length = 10000;
		vector<int>* testSet = generateShuffledSet(length);

		// <will> 
		// Comment these lines out if you don't want the set sorted.
		// If you do sort the set, comment out the sorting lines in algorithm 3
		vector<int>* sortedSet = Sorter::mergeSort(testSet);
		delete testSet;
		testSet = sortedSet;
		sortedSet = 0;

		vector<clock_t> results = testIsUniques(testSet);
		//cout << "isUnique1: " << results[0] << endl;
		cout << "isUnique2: " << results[0] << endl;
		cout << "isUnique3: " << results[1] << endl;
		return 0;
	}
	
	// <will>
	// Factors for vector length and vector length growth
	double factor = 2;
	double setLength = 4;
        
	// <will>
	// List of functions and whether or not they have run longer than the maximum time
	const int numFunctions = 3;
	IsUniqueMethod functions[numFunctions] = 
	{
		{ false, Sorter::isUnique1 },
		{ false, Sorter::isUnique2 },
		{ false, Sorter::isUnique3 },
	};

	// <will>
	// The maxium time a method is allowed to run (in milliseconds)
	int maxiumumDuration = 1000 * 60; // one minute

	// <will>
	// Loop until each function takes too long
	while (!functions[0].functionLongerThanMax || !functions[1].functionLongerThanMax || !functions[2].functionLongerThanMax)
	{
		// <will>
		// Generate a set of the appropriate legnth
		vector<int>* shuffledSet = generateShuffledSet(static_cast<int>(setLength));

		// <will>
		// Print the set to the console (for debugging purposes)
		/*cout << endl;
		for (unsigned int ii = 0; ii < shuffledSet->size(); ii++)
		{
			cout << (*shuffledSet)[ii] << " ";
		}
		cout << endl;*/

		// <will>
		// Loop through all functions and print the timing data
		cout << static_cast<int>(setLength);
		for (int ii = 0; ii < numFunctions; ii++)
		{
			if (!functions[ii].functionLongerThanMax)
			{
				// <will>
				// Run algorithm
				clock_t t = clock();
				functions[ii].function(shuffledSet, 0, static_cast<int>(setLength) - 1);
				t = clock() - t;

				// <will>
				// Print the time to run, and adjust the flag if necessary
				cout << "," << t;
				if (t > maxiumumDuration)
				{
					functions[ii].functionLongerThanMax = true;
				}
			}
			else
			{
				// <will>
				// If we have already gone over the max time, don't run the algorithm
				cout << "," << "--";
			}
		}
		cout << endl;

		// <will>
		// Clean up the set
		delete shuffledSet;
		shuffledSet = 0;

		// <will>
		// Increase the set size for the next iteration
		setLength *= factor;
	}

	return 0;
}

vector<int>* generateShuffledSet(int length)
{
	// <will>
	// Populate a new vector with values 1, 2, ... n, where n is the length. Then shuffle them.
	vector<int>* set = new vector<int>(length);
	for (int ii = 0; ii < length; ii++)
	{
		(*set)[ii] = ii;
	}
	std::random_shuffle ( set->begin(), set->end() );

	return set;
}

vector<clock_t> testSorts(vector<int>* set)
{
	// <will>
	// For each sort algorithm, sort the set and add the time to complete to the results vector
	vector<soringAlgorithm> sorts;
	sorts.push_back(Sorter::bubbleSort);
	sorts.push_back(Sorter::insertionSort);
	sorts.push_back(Sorter::mergeSort);
	vector<clock_t> results(sorts.size());

	for (unsigned int ii = 0; ii < sorts.size(); ii++)
	{
		clock_t t = clock();
		vector<int>* sorted = sorts[ii](set);
		t = clock() - t;
		results[ii] = t;

		delete sorted;
	}

	return results;
}

vector<clock_t> testIsUniques(vector<int>* set)
{
	// <will>
	// For each algorithm, add the time to complete to the results vector
	vector<isUnique> algorithms;
	//algorithms.push_back(Sorter::isUnique1);
	algorithms.push_back(Sorter::isUnique2);
	algorithms.push_back(Sorter::isUnique3);
	vector<clock_t> results(algorithms.size());

	for (unsigned int ii = 0; ii < algorithms.size(); ii++)
	{
		clock_t t = clock();
		algorithms[ii](set, 0, set->size() - 1);
		t = clock() - t;
		results[ii] = t;
	}

	return results;
}