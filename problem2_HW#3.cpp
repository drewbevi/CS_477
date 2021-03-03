#include <iostream>
using namespace std;
void findLilAndBig(int array[], int start,int end,int& min, int& max); //find min and max
int main()
{
    
    int arr[] = {1, 4, 9, 3, 4, 9, 5, 6, 9, 3, 7}, size = sizeof(arr)/sizeof(arr[0]), min = 10000, max = 0;
    findLilAndBig(arr,0, size - 1,min,max);
    cout <<"Of the array [1, 4, 9, 3, 4, 9, 5, 6, 9, 3, 7]..."<<endl;
    cout <<"Smallest Value: "<<min<<endl;
    cout <<"Largest Value: "<<max<<endl;
}
void findLilAndBig(int array[], int start,int end,int& min, int& max)
{
    int mid = (start + end) / 2; //Divide array in have then begin to compare each half
    if(start == end) //Base case, if size of array is = 1
    {
        if(min > array[end])    //Compare if current min value is larger than the end element in array
            min = array[end];   //if true the new min value is the value of said end element
        if(max < array[start])  //Compare if current max value is smaller than the start element in array
            max = array[start]; //if true the new max value is the value of said start element
        return;
    }
    if( (end-start) == 1) //Second base case, if size of array is = 2
    {
        if(array[start] < array[end])   //Compare if start element in array is less than end element in array
        {
            if(min > array[start])      //If true compare values at array start and end with current max and min values
                min = array[start];
            if(max < array[end])
                max = array[end];
        }
        else                            //If false compare values at array end and start with current max and min values
        {
            if(min > array[end])
                min = array[end];
            if(max < array[start])
                max = array[start];
        }
        return;
    }
    //Recur on the left side of array
    findLilAndBig(array, start, mid, min, max);
    //Recur on the right side of array
    findLilAndBig(array, mid+1, end, min, max);
}