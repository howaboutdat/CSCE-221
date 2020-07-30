// Add code everywhere you see this:
// Your code >>>

#include <iostream>
#include <stdio.h>
using namespace std;

int num_resize; // the number of resizes
int num_copy;  // the number of copied elements

void resize_array(int*& array, int& capacity)
{
	int* newArray = new int[capacity*2];
	for(int i = 0; i < capacity; i++)
		newArray[i]=array[i];
	num_copy = (num_copy + capacity)/2;
	capacity = capacity*2;
	delete[]array;
	array=newArray;
	num_resize++;
  // Your code >>> resize array by doubling its capacity
  // Your code >>> use tracker variables:
  //           >>> num_resize and num_copy
}

void add_elements(int start, int total_elem)
{
    // Clear tracker variables
    num_resize = num_copy = 0;

    // Initialize array
    int capacity = start;
    int size = 0;
    int* A = new int[capacity];

    // Add elements to array
    while (size < total_elem)
    {
        if (size == capacity) // Array is full; add more space
        {
		resize_array(A,capacity);
	  //Your code >>> resize array
        }
        ++size;
        int index = size - 1;
        A[index] = index*index; // new values
    }

    // Print tracking info
    cout << "Total elements: " << total_elem << endl;
    cout << "Resize " << num_resize << " times." << endl;
    cout << "Copied " << num_copy << " elements in total." << endl;
}

int main()
{
  // test this program
  int total_elem[]= {1, 2, 4, 64, 1024};
  for (int i = 0; i < 5; i++)
    add_elements(1, total_elem[i]);
}