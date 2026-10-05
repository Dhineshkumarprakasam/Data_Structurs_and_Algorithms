#include <iostream>
using namespace std;

void display(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

void heapify(int arr[], int n, int rootIndex){
    int root = rootIndex;
    int left = 2*rootIndex+1;
    int right = 2*rootIndex+2;

    if(left<n && arr[left]>arr[root])
        root = left;

    if(right<n && arr[right]>arr[root])
        root=right;

    if(root!=rootIndex){
        swap(arr[rootIndex],arr[root]);
        heapify(arr,n,root);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
  
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
  
    display(arr,n);
}

int main(){
    int arr[] = {7,2,5,1,3,6,4};
    heapSort(arr,7);
}
