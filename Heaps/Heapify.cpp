#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int index = i;
    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;
    int largest = index;

    if(leftIndex <= n && arr[largest] < arr[leftIndex])
        largest = leftIndex;
    if(rightIndex <= n && arr[largest] < arr[rightIndex])
        largest = rightIndex;
    if(index != largest){
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
}

void builtHeap(int arr[], int n) {
    for(int i = n/2; i > 0; i--) {
        heapify(arr,n,i); 
    }
}

void heapSort(int arr[], int n) {
    while(n != 1) {
        swap(arr[1], arr[n--]);
        heapify(arr, n, 1); // yaha pr index ki jagah 1 pass karna hai and yhi pr mistake hoti hai.
    }
}

int main()
{
    int arr[] = {-1,1,14,3,7,4,88,22,5};
    int n = 8;
    builtHeap(arr, n);
    cout<<"Printing heap:"<<endl;
    for(int i=0; i<=n; i++) {
        cout<< arr[i] <<" ";
    }

    heapSort(arr, n);
    cout<<endl;
    cout<<"Printing heap:"<<endl;
    for(int i=1; i<=n; i++) {
        cout<< arr[i] <<" ";
    }
    cout<<endl;
}