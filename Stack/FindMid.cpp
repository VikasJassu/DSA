#include<iostream>
#include<stack>

using namespace std;


void findMid(stack<int> &s, int totalSize) {

    if(totalSize == 0) {
        cout<<"Stack is empty"<<endl;
    }
    if((totalSize/2 + 1) == s.size()) {
        cout<<"Middle of stack is "<<s.top()<<endl;
        return;
    }

    int temp = s.top();
    s.pop();

    findMid(s,totalSize);
    //backtrack
    s.push(temp);
}
int main() 
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
   
    

    int totalSize = s.size();

    findMid(s, totalSize);


}