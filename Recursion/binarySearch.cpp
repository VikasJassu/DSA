#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> v , int s, int e, int key) {
    if(s>e) {
        return -1;
    }

    int mid = s + (e-s)/2;
    if(v[mid] == key) {
        return mid;
    }

    // if(v[mid] < key) {
    //     return binarySearch(v, mid+1, e, key);
    // }
    // else {
    //     return binarySearch(v, s, mid-1, key);
    // }

    //using ternary operator

    return (v[mid] < key) ? binarySearch(v, mid+1, e, key) : binarySearch(v, s, mid-1, key);
}

int main()
{
    vector<int> v{10,29,45,55,77,99};

    int key = 99;
    int n = v.size();
    int s = 0;
    int e = n-1;

    int ans= binarySearch(v , s ,e , key);

    cout<<"answer is: "<< ans <<endl;

}