#include <iostream>
using namespace std;
void merge(int array[], int L, int mM, int R);
void mergeSort(int array[], int size);
int findMin(int a, int b);
void printArray(int array[], int size);
int main()
{
    int arr[] = {1, 4, 9, 3, 4, 9, 5, 6, 9, 3, 7, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, size);
    printArray(arr, size);
    
    return 0;
}
int findMin(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}
void printArray(int array[],int size)
{
    cout<<"Original array: [1, 4, 9, 3, 4, 9, 5, 6, 9, 3, 7, 2]"<<endl<<"Sorted array: ["<<array[0];
    for(int i = 1; i <= size-1; i++)
        cout<<", "<<array[i];
    cout<<"]"<<endl;
}
void mergeSort(int array[], int size) 
{ 
   int currSize;  
   int start; 

   for (currSize=1; currSize<=size-1; currSize = 2*currSize) 
   { 
       for (start=0; start<size-1; start += 2*currSize) 
       { 
           int mid = findMin(start + currSize - 1, size-1); 
  
           int end = findMin( start + 2*currSize - 1, size-1); 
           merge(array, start, mid, end); 
       }
   } 
} 
void merge(int array[], int L, int M, int R) 
{ 
    int i, j, index = L, sR =  R - M, sL = M - L + 1; 
    int tempL[sL], tempR[sR]; 

    for (i = 0; i < sL; i++) 
        tempL[i] = array[L + i]; 
    for (j = 0; j <sR; j++) 
        tempR[j] = array[M + 1 + j];

    i = 0, j = 0;

    while (i < sL && j < sR) 
    { 
        if (tempL[i] <= tempR[j]) 
        { 
            array[index] = tempL[i], i++; 
            
        } 
        else
        { 
            array[index] = tempR[j], j++;
             
        } 
        index++; 
    } 
    while (i < sL) 
    { 
        array[index] = tempL[i]; 
        i++, index++;
    } 
    while (j < sR) 
    { 
        array[index] = tempR[j]; 
        j++, index++; 
    } 
} 