// Functions.cpp
// By: Sophia Moore
// Created on: 12/07/20

void swap_values(int& v1, int& v2)
{
    int temp;

    temp = v1;
    v1 = v2;
    v2 = temp;
}

int find_index_of_swap(bool descend, int arr[], int size, int start)
{
    int max_min = arr[start];
    int index_of_swap = start;
    
    for (int index = start + 1; index < (size + start); index++)
    // index < (size + start) b/c size keeps shrinking, but we want the sort to continue til end of the array
    {
        if ( ( (descend != 0) && (arr[index] > max_min) ) || ( (descend == 0) && (arr[index] < max_min) ) )
        // if descend is true/false and number after starting point is bigger/smaller than the OG #
        {
            // then the new max/min is the number with the new index
            // and the index of swap is the new index
            max_min = arr[index];
            index_of_swap = index;
        }
    }

    return index_of_swap;
}

void sort(bool descend, int arr[], int size, int start)
{
    if (size > 0)
    // if size is 0, then we've reached the end of the array so we should stop sorting
    {
        // 1. find index of swap
        // 2. swap values
        // 3. sort the remainder of the array
        int index_of_swap = find_index_of_swap(descend, arr, size, start);
        swap_values(arr[start], arr[index_of_swap]);
        sort(descend, arr, size-1, start+1);
    }

    return;
}

void getArray(ifstream& in, string fname, int arr[], int size)
{
    in.open(fname);
    if ( in.fail() ) 
    { 
        cerr << "Input file opening failed.\n"; 
        exit(1); 
    }
    for (int i = 0; i < size; i++)
    {
        in >> arr[i];
    }

    return;
}
