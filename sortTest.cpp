#include <iostream>
#include "Sorter.h"

using namespace std;

int main(){
    int myints[] = {2, 30, 19, 55, 1, 8, 4};
    vector<int>* test = new vector<int>;
    for( unsigned int ii = 0; ii < 7; ii++){
        test->push_back(myints[ii]);
    }
    cout << "My Vector:\n";
    for (unsigned int ii = 0 ; ii < test->size(); ii++)
    {
        cout << (*test)[ii] << " ";
    }
    cout << endl << endl;
    
    test = Sorter::bubbleSort(test);
    cout << "sorted." << endl;
    cout << "Sorted Vector:\n";
    for (unsigned int ii = 0 ; ii < test->size(); ii++)
    {
        cout << (*test)[ii] << " ";
    }
    cout << endl << endl;
    delete test;
    return 0;
}
