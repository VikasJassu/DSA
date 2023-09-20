#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseKElem(queue<int> &q, int k) {
    stack<int> s;
    int n = q.size();
    int count = 0;
    if(k <= 0 || k > n){
        return;
    }
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k) {
            break;
        }
    }

    while(!s.empty()) {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    count = 0;

    while(!q.empty() && n-k != 0) {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k){
            break;
        }
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

    int k = 3;

    reverseKElem(q,k);

    cout<<"Size of Q is: "<<q.size()<<endl;

    while(!q.empty()) {
        cout<< q.front()<<" ";
        q.pop();
    } 
    cout<<endl;
}
//TC O(n) and SC O(n)