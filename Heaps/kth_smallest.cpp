#include<iostream>
#include<queue>
using namespace std;

//iski TC minHeap and maxHeap mein same rahegi that is O(n) but SC maxHeap ki kam hogi that is O(k). So use maxHeap preferablly.
int kthSmallest(int arr[], int n, int k) {
    priority_queue<int> q;

    //starting ke k elements q mein push kro
    for(int i=0; i<k; i++) {
        q.push(arr[i]);
    }
    //now check every element. if element is less than q.top() then insert into q.
    for(int i=k; i<n; i++) {
        int elem = arr[i];

        if(elem < q.top()) {
            q.pop();
            q.push(elem);
        }
    }
    return q.top();
}


//iski TC minHeap and maxHeap mein same rahegi that is O(n) but SC minHeap ki kam hogi that is O(k). So use minHeap preferablly.
int kthGreatest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=0; i<k; i++) {
        q.push(arr[i]);
    }
    for(int i=k; i<n; i++) {
        int elem = arr[i];
        if(elem > q.top()) {
            q.pop();
            q.push(elem);
        }
    }
    return q.top();
}

int main()
{
    int arr[] = {3,7,2,8,1,9};
    int n = 6;
    int k = 2;

    int ans = kthSmallest(arr, n, k);
    cout<<"kth smallest is: "<<ans<<endl;

    int ans1 = kthGreatest(arr, n, k);
    cout<<"kth greatest is: "<<ans1<<endl;

}