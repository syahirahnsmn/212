/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
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

void readingArr(int S[], int n)
{
    int i;
    for (i=1;i<=n;i++){
        S[i] = 1+ rand() % 100; //insert random number into array
        if(i<n)
            cout<<S[i]<<", ";
        else
            cout<<S[i]<<". ";
    }
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

/* Function to print an array */
void printArr(int S[], int n)
{
    for (int i=1;i<=n;i++){
        if(i<n)
            cout<<S[i]<<", ";
        else
            cout<<S[i]<<". ";
    }
}

// Driver Code
int main()
{
    int n;
    cout<<"\n\n\t\tTHIS IS SORTING ALGORITHM USING INSERTION METHOD\n\n"
        <<"\n\t\tPlease insert your array size (suggested value 1000 - 10000):\n\n\t\t";
    cin>>n;
    int S[n];
    cout<<"\n\t\tRandom number generated of size " <<n<< ":\n"
        <<"\t\t----------------------------------\n\n\t\t";
    readingArr(S, n); //read random generated number into array
    quickSort(S, 1, n);
    cout << "Sorted array: \n";
    printArr(S, n);
    return 0;
}

// This code is contributed by rathbhupendra
