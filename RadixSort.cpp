/*
Algorithm: Radix Sort
Start.
Find the maximum element in the array.
Set pos = 1 to process the units digit.
For each position (1, 10, 100, ...) while max/pos > 0:
  Initialize count[10] with 0.
  Find the digit at the current position using:
  digit = (arr[i] / pos) % 10
  Increase count[digit].
  Perform cumulative sum on the count array.
  Traverse the original array from right to left.
  Use the cumulative count to place each element in the correct position of ans.
  Copy ans back to the original array.
  Move to the next digit position by multiplying pos by 10.
Print the sorted array.
Stop.
*/

#include <iostream>
using namespace std;

void count_sort(int arr[], int n, int pos){

    //initialize with 0 for digits 0-9
    int count[10] = {0};

    /*
    increment in count for value of given place
        - eg.if arr[i]=432, 432/1 = 432%10 = 2, count[2]++
        - eg.if arr[i]=90, 90/1 = 90%0 = 0, count[0]++
    */

    for(int i=0; i<n; i++){
        count[arr[i]/pos%10]++;
    }

    cout<<"Count      : ";
    for(int i=0; i<10; i++)
        cout<<count[i]<<" ";
    cout<<endl;

    /*
    perform cumulation on count array
        eg. 1 2 3 4 = 1 3 6 10
    */

    for(int i=1;i<10;i++){
        count[i] = count[i]+count[i-1];
    }

    cout<<"Cumulation : ";
    for(int i=0; i<10; i++)
        cout<<count[i]<<" ";
    cout<<endl;

    /*
    Steps:
        1.read arr from right to left
        2.take value from count for particular place of arr[i]
        3.reduce it by 1 : use this as index of ans to store in ans
    */

    int ans[n];

    for(int i=n-1;i>=0;i--){
        ans[--count[(arr[i]/pos)%10]] = arr[i];
    }

    //store back in orginal arr
    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }

    cout<<"Sorted for "<<pos<<"'s place : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl<<endl;
}

void radix_sort(int arr[],int n){

    //finding maximum in array
    int max = arr[0];

    for(int i = 1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    //position : 1 to n(no of plces in maximum value)
    for(int pos=1;(max/pos)>0;pos*=10)
        count_sort(arr,n,pos);
}

int main(){

    int arr[] = {10,22,198,13,2,4,811,32,11,200};
    int n = 10;

    cout<<"Before : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl<<endl;

    radix_sort(arr,n);

    cout<<"After : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}
