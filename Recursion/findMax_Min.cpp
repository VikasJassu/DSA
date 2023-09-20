#include<iostream>
#include<limits.h>
using namespace std;

void findMax(int arr[], int n, int i,int& maxi) {
    if(i>=n)
    return;

    maxi = max(maxi , arr[i]);

    findMax(arr,n,i+1,maxi);
   
}
void findMin(int arr[], int n, int i,int& mini) {
    if(i>=n)
    return;

    mini = min(mini , arr[i]);

    findMin(arr,n,i+1,mini);
}
int main()
{
    int arr[] = {10,20,3,55,88,2,40,5};
    int n = 8;
    int i = 0;
    int maxi = INT_MIN;
    findMax(arr,n,i,maxi);
    cout<<"Maximum number is: "<<maxi<<endl;

    int mini = INT_MAX;
    findMin(arr,n,i,mini);
    cout<<"Minimum number is: "<<mini<<endl;
}

