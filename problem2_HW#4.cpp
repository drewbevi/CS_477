#include <iostream>
using namespace std;
#define N 12
void swapValue(int *a, int *b);
void printArray(int array[]);
int Partition(int array[], int low, int high);
void rearrangeNegToPos(int array[], int low, int high);
int main()
{
    int arr[] = {4, 3, -2, 0, 2, 9, -1, 10, 0, 5, 23, -4};
    rearrangeNegToPos(arr,0,N-1);
    printArray(arr);
}
void swapValue(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    
}
void printArray(int array[])
{
    cout<<"Original array: [4, 3, -2, 0, 2, 9, -1, 10, 0, 5, 23, -4]"<<endl<<"Numerically sorted array: ["<<array[0];
    for(int i = 1; i <= N-1; i++)
        cout<<", "<<array[i];
    cout<<"]"<<endl;

}
void rearrangeNegToPos(int array[], int low, int high)
{
    if(low < high)
    {
        int indexP = Partition(array,low,high); //addreviation for index of the partitioned value
        rearrangeNegToPos(array,low,indexP);
        rearrangeNegToPos(array,indexP+2,high);
    }
}
int Partition(int array[], int low, int high)
{
    int pivot = 0; 
    int i = low-1;
    for(int j = low; j <= high-1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swapValue(&array[i], &array[j]);
        }
    }
    swapValue(&array[i+1], &array[high]);
    return i;
}