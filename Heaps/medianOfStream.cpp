#include<iostream>
#include<queue>
using namespace std;

int signum(int a, int b) {
    if(a == b) {
        return 0;
    }
    if(a > b) {
        return 1;
    }
    if(a < b) {
        return -1;
    }
}
void findMedian(double &median, int elem, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap ) {
    int a = minHeap.size();
    int b = maxHeap.size();

    switch(signum(a,b)) {
        case 0:
                if(elem > median) {
                    minHeap.push(elem);
                    median = minHeap.top();
                }
                else{
                    maxHeap.push(elem);
                    median = maxHeap.top();
                }
                break;
        case 1:
                if(elem > median) {
                    int topElem = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(topElem);
                    minHeap.push(elem);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
                else{
                    maxHeap.push(elem);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
                break;
        case -1:
                if(elem > median) {
                    minHeap.push(elem);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
                else{
                    int topElem = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(topElem);
                    maxHeap.push(elem);
                    median = (minHeap.top() + maxHeap.top())/2.0;
                }
                break;
    }

    //solution without using switch statement
    /*if(a == b) {
        if(elem > median) {
            minHeap.push(elem);
            median = minHeap.top();
        }
        else{
            maxHeap.push(elem);
            median = maxHeap.top();
        } 
    }
    else if(a < b) {
        if(elem > median) {
            minHeap.push(elem);
            median = (minHeap.top() + maxHeap.top())/2;
        }
        else{
            int topElem = maxHeap.top();
            maxHeap.pop();
            minHeap.push(topElem);
            maxHeap.push(elem);
            median = (minHeap.top() + maxHeap.top())/2;
        }
    }
    else{
        if(elem > median) {
            int topElem = minHeap.top();
            minHeap.pop();
            maxHeap.push(topElem);
            minHeap.push(elem);
            median = (minHeap.top() + maxHeap.top())/2;
        }
        else{
            maxHeap.push(elem);
            median = (minHeap.top() + maxHeap.top())/2;
        }
    } */
}

int main()
{
    int arr[12] = {5,15,1,3,2,8,7,9,10,6,11,4};
    int n = 12;

    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++) {
        int element = arr[i];
        findMedian(median, element, maxHeap, minHeap);
        cout<<"median-> "<<median<<endl;
    }

}