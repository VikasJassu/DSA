#include<iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int> &v , int& n , int i) {
    if(i ==n-1) {
        return true;
    }

    if(v[i+1] < v[i]) {
        return false;
    }

     return checkSorted(v , n , i+1);
}

int main()
{
    vector<int> v{1,2,3,4,5};
    int n = v.size();
    int i = 0;
    bool isSorted = checkSorted(v , n , i);
    if(isSorted) {
        cout<<"array is sorted"<<endl;
    }

    else {
        cout<<"array is not sorted"<<endl;
    }
}