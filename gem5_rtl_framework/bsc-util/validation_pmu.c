// example1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef ENABLE_PARSEC_HOOKS
#include "hooks.h"

#endif

//#define ARRAYSIZE 16000000
#define CACHESIZE 64*1024*8 // (8192*4 = 32KB) anyways * 2 JIC

#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <iostream>

using namespace std;
// Swap two elements - Utility function
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}


/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool checkSorted(int arr[], int size)
{
    int i;
    int aux = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] < aux)
           return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    int size = 0;
    srand (time(NULL));
    int *arr1,*arr2,*arr3,*arr4;
    size = atoi(argv[1]);
    arr1 = (int *) aligned_alloc(sizeof(int)*16,sizeof(int)*size);
    arr2 = (int *) aligned_alloc(sizeof(int)*16,sizeof(int)*size);
    arr3 = (int *) aligned_alloc(sizeof(int)*16,sizeof(int)*size);
    arr4 = (int *) aligned_alloc(sizeof(int)*16,sizeof(int)*size*10);
    //char *ptr = (char *)a;
    for (int i = 0; i < size; i++) {
        int aux = rand()%100000;
        arr1[i] = aux;
        arr2[i] = aux;
        arr3[i] = aux;
        arr4[i] = aux;
    }

#ifdef ENABLE_PARSEC_HOOKS
    __parsec_roi_begin();
#endif

    //#ifdef ENABLE_PARSEC_HOOKS
    //__start_accel(arr1,size,arr1);
    //#endif

    cout << "QuickSort\n";

    quickSort(arr1, 0, size - 1);

    /*cout << "Sorted array is: ";
    //printArray(arr1, n);
    if (checkSorted(arr1, size)) {
        cout << "Sorted\n";
    }
    else {
        cout << "Bad Sorted\n";
    }*/

    usleep(1000);

    cout << "\nSelection sort\n";

    selectionSort(arr2, size/10);

    /*cout << "Sorted array is: ";
    if (checkSorted(arr2, size)) {
        cout << "Sorted\n";
    }
    else {
        cout << "Bad Sorted\n";
    }*/

    usleep(1000);

    cout << "\nBubble sort\n";
    bubbleSort(arr3, size/10);
    //cout<<"Sorted array is: ";
    /*if (checkSorted(arr3, size)) {
        cout << "Sorted\n";
    }
    else {
        cout << "Bad Sorted\n";
    }*/

    /*cout << "\nMerge sort\n";

    mergeSort(arr2, 0, size - 1);

    printf("Sorted array is: ");
    if (checkSorted(arr2, size)) {
        cout << "Sorted\n";
    }
    else {
        cout << "Bad Sorted\n";
    }
    //printArray(arr2, size);

    cout << "\nBubble sort\n";
    bubbleSort(arr3, size);
    cout<<"Sorted array is: ";
    if (checkSorted(arr3, size)) {
        cout << "Sorted\n";
    }
    else {
        cout << "Bad Sorted\n";
    }
    //printArray(arr, size);

    cout << "\nSelection sort\n";
    selectionSort(arr4, size);
    cout << "Sorted array is: ";
    if (checkSorted(arr4, size)) {
        cout << "Sorted\n";
    }
    else {
        cout << "Bad Sorted\n";
    }
    //printArray(arr, n); */

    //#ifdef ENABLE_PARSEC_HOOKS
    //__wait_accel(arr1,size);
    //#endif



#ifdef ENABLE_PARSEC_HOOKS
    __parsec_roi_end();
#endif

    return 0;
}
