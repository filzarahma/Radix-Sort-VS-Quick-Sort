#include <iostream>
#include <chrono> // To measure execution time
using namespace std;

// Function to get the maximum element from an array
int getMax(int array[], int n)
{
  /*
  I.S. An integer array with n elements is provided
  F.S. The largest element in the array is returned
  Purpose: This function determines the largest number in the array to
  identify the maximum number of digits we need to sort.
  */
  int max = array[0];         // Assume the first element is the largest initially
  for (int i = 1; i < n; i++) // Traverse the rest of the array
  {
    if (array[i] > max) // Update max if a larger number is found
      max = array[i];
  }
  return max;
}

// Function to perform counting sort based on a specific digit place
void countingSort(int array[], int size, int place)
{
  /*
  I.S. An integer array, its size, and a place value for digit sorting are provided
  F.S. The array is sorted in ascending order based on the digit at the given place
  Purpose: To sort numbers based on individual digit places using counting sort.
  */
  const int base = 10;   // Base for decimal numbers (0-9)
  int output[size];      // Temporary array to store sorted elements
  int count[base] = {0}; // Array to count occurrences of digits (initialized to 0)

  // Step 1: Count the occurrences of each digit at the specified place
  for (int i = 0; i < size; i++)
  {
    int digit = (array[i] / place) % 10; // Extract the digit at the current place
    count[digit]++;                      // Increment the count of the extracted digit
  }

  // Step 2: Calculate cumulative counts to determine positions in the output array
  for (int i = 1; i < base; i++)
  {
    count[i] += count[i - 1];
  }

  // Step 3: Build the sorted array based on cumulative counts
  for (int i = size - 1; i >= 0; i--) // Traverse from the end to maintain stable sorting
  {
    int digit = (array[i] / place) % 10; // Extract the digit again
    output[count[digit] - 1] = array[i]; // Place the element in the correct position
    count[digit]--;                      // Decrement the count for that digit
  }

  // Step 4: Copy the sorted elements back to the original array
  for (int i = 0; i < size; i++)
  {
    array[i] = output[i];
  }
}

// Function to implement radix sort
void radixSort(int array[], int size)
{
  /*
  I.S. An integer array with its size is provided
  F.S. The array is sorted in ascending order
  Purpose: To repeatedly apply counting sort to sort numbers based on individual digits,
  starting from the least significant digit (LSD) to the most significant digit (MSD).
  */
  int max = getMax(array, size); // Step 1: Find the maximum element in the array

  // Step 2: Perform counting sort for each digit place (units, tens, hundreds, etc.)
  for (int place = 1; max / place > 0; place *= 10) // Iterate through place values
  {
    countingSort(array, size, place); // Sort the array by the current place value
  }
}

// Function to print the array
void printArray(int array[], int size)
{
  /*
  I.S. An integer array with its size is provided
  F.S. The array is printed to the console
  Purpose: To display the elements of the array.
  */
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

// Main Program
int main()
{
  // Step 1: Initialize the array to be sorted
  int array[] = {121, 432, 564, 23, 1, 45, 788}; // Example input array
  int n = sizeof(array) / sizeof(array[0]);      // Calculate the number of elements

  cout << "Unsorted Array:\n";
  printArray(array, n); // Display the unsorted array

  cout << "\nStarting Radix Sort...\n";

  // Step 2: Measure the execution time of the radix sort algorithm
  auto start = chrono::high_resolution_clock::now(); // Start the timer
  radixSort(array, n);                               // Perform the radix sort
  auto stop = chrono::high_resolution_clock::now();  // Stop the timer

  cout << "\nSorted Array:\n";
  printArray(array, n); // Display the sorted array

  // Step 3: Calculate and display the elapsed time
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cout << "\nTime taken by Radix Sort: " << duration.count() << " microseconds\n";

  return 0; // Indicate successful program termination
}
