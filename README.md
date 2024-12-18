# Quick Sort and Radix Sort Algorithms

This project provides implementations of two classic sorting algorithms: **Quick Sort** and **Radix Sort**. Each algorithm is designed for specific use cases, offering efficient sorting solutions for arrays of integers. This repository also includes performance tracking for both algorithms, providing insights into their execution times.

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [Quick Sort Implementation](#quick-sort-implementation)
3. [Radix Sort Implementation](#radix-sort-implementation)
4. [Performance Comparison](#performance-comparison)
5. [How to Use](#how-to-use)
6. [Dependencies](#dependencies)
7. [Online Compiler Option](#online-compiler-option)
8. [Acknowledgments](#acknowledgments)

---

## Project Overview

Sorting algorithms are fundamental to computer science and software development. This project showcases two well-known algorithms:

1. **Quick Sort**: A divide-and-conquer algorithm that partitions the array around a pivot and recursively sorts the partitions.
2. **Radix Sort**: A non-comparative sorting algorithm that processes integer digits from the least significant digit (LSD) to the most significant digit (MSD).

Both algorithms are implemented with detailed verbosity for educational purposes, including step-by-step explanations and execution time tracking.

---

## Quick Sort Implementation

### Features

-   **Recursive Divide-and-Conquer**:
    -   Partitions the array into two subarrays around a pivot.
    -   Recursively sorts each partition.
-   **Pivot Selection**: The last element of the array is used as the pivot.
-   **In-Place Sorting**: Reduces memory overhead by swapping elements directly in the array.

### Steps

1. Choose a pivot element.
2. Partition the array such that elements less than or equal to the pivot are on the left, and greater elements are on the right.
3. Recursively apply Quick Sort to the left and right partitions.

### Example Output

-   **Unsorted Array**: `{10, 0, 3, 2, 5, 4, 4, 1, 9}`
-   **Sorted Array**: `{0, 1, 2, 3, 4, 4, 5, 9, 10}`
-   **Execution Time**: ~`X microseconds` (varies based on input size).

---

## Radix Sort Implementation

### Features

-   **Non-Comparative Sorting**:
    -   Uses counting sort as a subroutine for each digit position.
-   **Handles Large Integers**: Efficiently sorts integers by processing digits individually.
-   **Stable Sorting**: Maintains the relative order of equal elements.

### Steps

1. Find the maximum number to determine the number of digits.
2. Apply counting sort iteratively for each digit position, starting from the LSD to the MSD.
3. Combine results to achieve the final sorted array.

### Example Output

-   **Unsorted Array**: `{121, 432, 564, 23, 1, 45, 788}`
-   **Sorted Array**: `{1, 23, 45, 121, 432, 564, 788}`
-   **Execution Time**: ~`X microseconds` (varies based on input size).

---

## Performance Comparison

The project tracks the execution time for both algorithms, highlighting their efficiency based on the input array. Key factors include:

-   **Quick Sort**:

    -   Best for general-purpose sorting with average-case complexity \(O(n \log n)\).
    -   May degrade to \(O(n^2)\) in the worst case with poor pivot selection.

-   **Radix Sort**:
    -   Best for sorting large integers with complexity \(O(n \cdot k)\), where \(k\) is the number of digits.
    -   Requires additional space for counting arrays.

---

## How to Use

1. Clone the repository:

    ```bash
    git clone https://github.com/filzarahma/Radix-Sort-VS-Quick-Sort.git
    cd sorting-algorithms
    ```

2. Compile the code:

    ```bash
    g++ quick_sort.cpp -o quick_sort
    g++ radix_sort.cpp -o radix_sort
    ```

3. Run the programs:

    - Quick Sort:
        ```bash
        ./quick_sort
        ```
    - Radix Sort:
        ```bash
        ./radix_sort
        ```

4. Observe the sorted output and execution time in the console.

---

## Dependencies

This project requires the following tools:

-   **C++ Compiler**: Ensure you have a modern C++ compiler (e.g., GCC, Clang) that supports C++11 or higher.
-   **Standard Libraries**: Includes `<iostream>` and `<chrono>` for basic operations and time measurement.

---

## Online Compiler Option

If you do not have a C++ compiler installed on your local machine, you can use an online compiler to run the programs. Here are the steps:

1. Open an online C++ compiler, such as [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler).
2. Copy and paste the contents of `quick_sort.cpp` or `radix_sort.cpp` into the editor.
3. Click the **Run** button to execute the program.
4. Observe the results in the output console.

Alternatively, you can use any other online compiler of your choice.

---

## Acknowledgments

This project draws inspiration from:

-   The fundamental concepts of sorting algorithms taught in computer science courses.
-   Resources on algorithm design and analysis.

If you find this repository helpful, feel free to cite or reference it in your work.
