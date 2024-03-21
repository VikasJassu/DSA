#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int target) {
    int s=0;
    int e=n-1;
    int mid= s+(e-s)/2;

    while(s<=e) {
        if(arr[mid]==target) {
            return mid;
        }
        else if(arr[mid]>target) {
            e= mid-1;
        }
        else {
            s=mid+1;
        }
         mid= s+(e-s)/2;
    }

    return -1;
}
int main()
{
    int arr[7] = {3,5,6,7,9,10,13};
    int target;
    cout<<"enter number to find "<<endl;
    cin>>target;
    int element = binarySearch(arr,7,target);
    cout<<"element found at index "<<element<<endl;

}