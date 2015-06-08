// SetEfficiency.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <time.h>

#include "TestSets.h"
#include "Sorter.h"

using namespace std;

// utility methods
void printTableRow(int n, double time1, double time2, double time3);

int main()
{
	TestSets* testSets = new TestSets();

	int sizes[] = { 10, 50, 100, 500, 1000 };
	int numSizes = 5;
	// <will>
	// Add the sets to the testSets instance. This should be changed to include better sets.
	for (int ii = 0; ii < numSizes; ii++)
	{
		int size = sizes[ii];
		int* set = new int[size];
		for (int ii = 0; ii < size; ii++)
		{
			set[ii] = ii;
		}
		testSets->addSet(set, size);
	}

	// <will>
	/* Printing out the sets for debugging purposes
	for (int ii = 0; ii < numSizes; ii++)
	{
		int size = sizes[ii];
		int* set = testSets->getSet(size);
		for (int ii = 0; ii < size; ii++)
		{
			cout << set[ii] << " ";
		}
		cout << endl;
	}*/

	cout << "   n   | isUnique1 | isUnique2 | isUnique3 " << endl;
	// <will>
	// Run the tests and print out the result
	for (int ii = 0; ii < numSizes; ii++)
	{
		int size = sizes[ii];
		int* set = testSets->getSet(size);

		// isUnique1()
		clock_t t1;
		t1 = clock();
		Sorter::isUnique1(set, 0, size);
		t1 = clock() - t1;

		// isUnique2()
		clock_t t2;
		t2 = clock();
		Sorter::isUnique2(set, 0, size);
		t2 = clock() - t2;

		// isUnique3()
		clock_t t3;
		t3 = clock();
		Sorter::isUnique3(set, 0, size);
		t3 = clock() - t3;

		printTableRow(size, t1, t2, t3);
	}

	// <will>
	// Clean up
	delete testSets;
	testSets = 0;

	return 0;
}

void printTableRow(int n, double time1, double time2, double time3)
{
	cout << setw(6) << n << " | ";
	cout << setw(9) << time1 << " | ";
	cout << setw(9) << time2 << " | ";
	cout << setw(9) << time3 << endl;
}
