#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &s, int target) {
    if(s.empty()) {
        s.push(target);
        return;
    }
    if(s.top() >= target) {
        s.push(target);
        return;
    }

    int topElem = s.top();
    s.pop();

    insertSorted(s,target);
    //backtracking
    s.push(topElem);
}

void sorted(stack<int> &s) {
    if(s.empty()) {
        return;
    }

    int target = s.top();
    s.pop();

    sorted(s);
    //backtracking
    insertSorted(s,target);

}


int main()
{
    stack<int> s;
    s.push(9);
    s.push(2);
    s.push(6);
    s.push(1);
    s.push(8);

     

    sorted(s);
    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }

}