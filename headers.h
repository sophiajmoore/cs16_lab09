// Headers.h
// By: Sophia Moore
// Created on: 12/07/20

void swap_values(int& v1, int& v2);
// Pre-condition: two integer variables
// Post-condition: the variables now have their values swapped

int find_index_of_swap(bool descend, int arr[], int size, int start);
// Pre-condition: takes in whether descending/ascending, an array, its size, and the starting point
// Post-condition: returns the integer index of whichever index needs to be swapped

void sort(bool descend, int arr[], int size, int start);
// Pre-condition: takes in whether descending/ascending, an array, its size, and the starting point
// Post-condition: a sorted array, either descending or ascending

void getArray(ifstream& in, string fname, int arr[], int size);
// Pre-condition: an empty array and a file of integer values
// Post-condition: the values in the file in the  array

const int MAXSIZE = 20;
const std::string FILENAME = "ArrayFile.txt";

