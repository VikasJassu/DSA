#include<iostream>
#include<queue>
using namespace std;

class info{
    public:
        int data;
        int row;
        int col;

        info(int data, int r, int c) {
            this->data = data;
            row = r;
            col = c;
        }
};

class compare{
    public:
        bool operator()(info*a, info*b) {
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArray(int arr[][4], int k, int n) {
    priority_queue<info*, vector<info*>, compare> minHeap;

     //first step is get first elem of all arrays
    for(int i=0; i<k; i++) {
        info* firstElem = new info(arr[i][0], i, 0);
        minHeap.push(firstElem);
    }

    vector<int> ans;
    while(!minHeap.empty()) {
       
        //2nd step: get top elem of minHeap and insert into ans
        info* temp = minHeap.top();
        int topElem = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();
        ans.push_back(topElem);
       

        if(topCol + 1 < n) {
            info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);
            minHeap.push(newInfo);
        } 
    }
    return ans;
    
}

int main()
{
    int arr[][4] = {{2,4,6,8},{1,3,5,7},{0,9,10,11}};
    int n = 4;
    int k = 3;
    vector<int> ans = mergeKSortedArray(arr,k,n);
    // for(auto i: ans) {
    //     cout<< i << " ";
    // }cout<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    } cout<<endl;
}