#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    if(q.empty()) {
        cout<<"Q empty haiii..."<<endl;
        return;
    }

    queue<int> q1;
    int count = 0;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        q1.push(temp);
        count++;

        if(count == n/2) {
            break;
        }
    }

    count = 0;
    while(!q.empty() && !q1.empty()) {
        int temp = q.front();
        q.pop();
        int temp2 = q1.front();
        q1.pop();
        q.push(temp2);
        q.push(temp);
        count++;
    }

    //if n is odd
    if(n&1) {
        int elem = q.front();
        q.pop();
        q.push(elem);
    }
}
int main()
{
    queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // q.push(70);
    // q.push(80);

    

    interleave(q);

    cout<<"Size of Q is: "<<q.size()<<endl;

    while(!q.empty()) {
        cout<< q.front()<<" ";
        q.pop();
    } 
    cout<<endl;
}
//TC O(n) and SC O(n)