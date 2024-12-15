#include <iostream>
#include <chrono> // To measure execution time
using namespace std;

// Function to swap two integer values
void swapValues(int *x, int *y)
{
  /*
  I.S. Two integer pointers, x and y, are provided
  F.S. The values pointed to by x and y are swapped
  Purpose: To exchange the values of two variables
  */
  int temp = *x;
  *x = *y;
  *y = temp;
}

// Function to print the elements of an array
void printArray(int array[], int size)
{
  /*
  I.S. An integer array and its size are provided
  F.S. The array elements are printed to the console
  Purpose: To display the current state of the array
  */
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

// Function to partition the array and return the partition index
int partition(int array[], int low, int high)
{
  /*
  I.S. An integer array, and low and high indices are provided
  F.S. The array is partitioned around a pivot, and the pivot index is returned
  Purpose: To divide the array into two parts: elements smaller than or equal to
  the pivot and elements greater than the pivot
  */
  int pivot = array[high]; // Select the last element as the pivot
  int i = (low - 1);       // Pointer for the smaller element

  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot) // If the current element is smaller than or equal to the pivot
    {
      i++;
      swapValues(&array[i], &array[j]); // Swap elements
    }
  }

  // Swap the pivot element with the element at i+1
  swapValues(&array[i + 1], &array[high]);

  return (i + 1); // Return the partition index
}

// Function to implement Quick Sort
void quickSort(int array[], int low, int high)
{
  /*
  I.S. An integer array and low and high indices are provided
  F.S. The array is sorted in ascending order
  Purpose: To recursively sort the array using the divide-and-conquer approach
  */
  if (low < high)
  {
    int pi = partition(array, low, high); // Find the pivot index

    // Recursively sort elements before and after the pivot
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

// Main program
int main()
{
  // Step 1: Initialize the array to be sorted
  int array[] = {10, 0, 3, 2, 5, 4, 4, 1, 9}; // Example input array
  int n = sizeof(array) / sizeof(array[0]);   // Calculate the number of elements

  cout << "Unsorted Array:\n";
  printArray(array, n); // Display the unsorted array

  cout << "\nStarting Quick Sort...\n";

  // Step 2: Measure the execution time of the Quick Sort algorithm
  auto start = chrono::high_resolution_clock::now(); // Start the timer
  quickSort(array, 0, n - 1);                        // Perform Quick Sort
  auto stop = chrono::high_resolution_clock::now();  // Stop the timer

  // Step 3: Display the sorted array
  cout << "\nSorted Array in Ascending Order:\n";
  printArray(array, n);

  // Step 4: Calculate and display the elapsed time
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cout << "\nTime taken by Quick Sort: " << duration.count() << " microseconds\n";

  return 0; // Indicate successful program termination
}
