#include "stdafx.h"

#include <iostream>
#include <vector>
#include <cmath>
#include "Sorter.h"

using namespace std;

//Bubble sorts an int vector in ascending order

vector<int>* Sorter::bubbleSort(vector<int>* unsorted) {
	vector<int>* sorter = new vector<int>(*unsorted);
    for (unsigned int ii = 0; ii < sorter->size(); ii++) {
        bool swapped = false;
        for (unsigned int jj = 0; jj < sorter->size() - ii; jj++) {
            if ((jj + 1 < sorter->size())) {
                if (sorter->at(jj) > sorter->at(jj + 1)) {
                    int temp = sorter->at(jj + 1);
                    sorter->at(jj + 1) = sorter->at(jj);
                    sorter->at(jj) = temp;
                    swapped = true;
                }
            }
        }
        if (!swapped) {
            return sorter;
        }
    }
    return sorter;
}

//tests to see if an int vector is sorted in ascending order
bool Sorter::isSorted(vector<int>* sort_vector){
  for(unsigned int i = 0; i < sort_vector->size()-1; i++){
    if((*sort_vector)[i] > (*sort_vector)[i+1]){
      return false;
    }
  }
  return true;
}

//merges two int vectors together in ascending sorted order
vector<int>* Sorter::merge(vector<int>* a, vector<int>* b){
  unsigned int ia = 0;
  unsigned int ib = 0;
  vector<int>* sorter = new vector<int>;
  while(ia < a->size() || ib < b->size()){
    if(ib == b->size()){
      sorter->push_back((*a)[ia]);
      ia++;
    }
    else if(ia == a->size()){
      sorter->push_back((*b)[ib]);
      ib++;
    }
    else if((*a)[ia] < (*b)[ib]){
      sorter->push_back((*a)[ia]);
      ia++;
    }
    else{
      sorter->push_back((*b)[ib]);
      ib++;
    }
  }
  return sorter;
}

//merge sorts an vector of strings in ascending order
vector<int>* Sorter::mergeSort(vector<int>* merger){

  /*cout << "taking in:";
  for (unsigned int ii = 0; ii < merger->size(); ii++){
    cout << merger->at(ii) << " ";
  }
  cout << endl;*/
  
  
  if(merger->size() <= 1){
    return merger;
  }
  if(!Sorter::isSorted(merger)){
    vector<int>* temp1 = new vector<int>;
    vector<int>* temp2 = new vector<int>;
    unsigned int middle = merger->size()/2;
    for(unsigned int i = 0; i < merger->size(); i++){
      if(i < middle){
        temp1->push_back((*merger)[i]);
      }
      else{
        temp2->push_back((*merger)[i]);
      }
    }
    temp1 = mergeSort(temp1);
    temp2 = mergeSort(temp2);
    merger = merge(temp1, temp2);
    delete temp1;
    delete temp2;
      /*cout << "giving back:";
      for (unsigned int ii = 0; ii < merger->size(); ii++){
        cout << merger->at(ii) << " ";
      }
      cout << endl;*/
    return merger;
  }
  
  /*cout << "did nothing:";
  for (unsigned int ii = 0; ii < merger->size(); ii++){
    cout << merger->at(ii) << " ";
  }
  cout << endl;*/
  return merger;
}


//insertion sorts an int vector in ascending order
vector<int>* Sorter::insertionSort(vector<int>* unsorted){
  vector<int>* sorted = new vector<int>;
  sorted->resize(unsorted->size());
  int unsorted_index = 0;
  for(unsigned int nextPos = unsorted_index; nextPos < unsorted->size(); nextPos++){
    int nextVal = (*unsorted)[unsorted_index];
    int tempPos = nextPos;
    while(tempPos > 0 && (*sorted)[tempPos-1] > nextVal){
      (*sorted)[tempPos] = (*sorted)[tempPos-1];
      tempPos--;
    }
    (*sorted)[tempPos] = nextVal;
    unsorted_index++;
  }
  return sorted;
}

bool Sorter::isUnique1( vector<int>* A, int first, int last )
{
    //cout << "comparing " << first << " and  " << last << endl;
    if( first >= last )
        return true;
    if( !isUnique1( A, first, last-1 ) )
        return false;
    if( !isUnique1( A, first+1, last ) )
        return false;
    return( (*A)[first] != (*A)[last] );
}

bool Sorter::isUnique2( vector<int>* A, int first, int last )
{
    if( first >= last )
        return true;
    for( int i = first; i < last; i++ )
    {
        for( int j = i+1; j <= last; j++ )
        {
            if( (*A)[i] == (*A)[j] )
                return false;
        }
    }
    return true;
}

bool Sorter::isUnique3( vector<int>* A, int first, int last )
{
    if( first >= last )
        return true;
    vector<int>* sorted = mergeSort( A );
    for(int i = first; i < last; i++)
    {
        if((*A)[i] == (*A)[i+1])
            return false;
    }
    return false;
}



