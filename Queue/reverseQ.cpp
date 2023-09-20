#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseWithRecursion(queue<int> &q) {
    if(q.empty()) {
        return;
    }

    int temp = q.front();
    q.pop(); 
    reverseWithRecursion(q);
    
    q.push(temp);

}

void reverseWithStack(queue<int> &q) {
    stack<int> s;

    while(!q.empty()) {
        int elem = q.front();
        q.pop();
        s.push(elem);
    }
    while(!s.empty()) {
        int elem = s.top();
        s.pop();
        q.push(elem);
    }

}


int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseWithRecursion(q);

    cout<<"Size of Q is: "<<q.size()<<endl;

    while(!q.empty()) {
        cout<< q.front()<<" ";
        q.pop();
    } 
    cout<<endl;
}