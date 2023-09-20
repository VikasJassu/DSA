#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target) {
    if(s.empty()) {
        s.push(target);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s,target);

    s.push(top);
}

void Reverse(stack<int> &s) {
    if(s.empty()) {
        return;
    }

    int target = s.top();
    s.pop();


    Reverse(s);
    
    insertAtBottom(s,target);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

     Reverse(s);

    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }

}