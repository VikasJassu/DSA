#include<iostream>

using namespace std;

class Queue {
    public: 
            int *arr;
            int size;
            int front;
            int rear;

            Queue(int size) {
                arr = new int[size];
                this->size = size;
                front = 0;
                rear = 0;
            }


            void push(int data) {
                if(rear == size) {
                    cout<<"Q is full" << endl;
                }
                else {
                    arr[rear] = data;
                    rear++;
                }
            }

            void pop() {
                if(front == rear) {
                    cout<<"Q is empty"<<endl;
                }
                else{
                    arr[front] = -1;
                    front++;
                    if(front == rear) {
                        front = 0;
                        rear = 0;
                    }
                }
            }

            int getFront() {
                if(front == rear) {
                     cout<<"Q is empty"<<endl;
                     return -1;
                }
                else{
                    return arr[front];
                }
            }

            bool isEmpty() {
                  if(front == rear) {
                     return true;
                }
                else{
                    return false;
                }
            }

            int getSize() {
                return rear - front;
            }
};

int main() {

    Queue q(10);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout<<"Size of Q is: "<<q.getSize()<<endl;

    q.pop();

    cout<<"Size of Q is: "<<q.getSize()<<endl;

    if(q.isEmpty()) {
        cout<<"Q is empty"<<endl;
    }
    else{
        cout<<"Q is not empty"<<endl;
    }

    cout<<"Front of Q is: "<< q.getFront()<<endl;

    while(!q.isEmpty()) {
        cout<<q.getFront()<<" ";
        q.pop();
    }
    cout<<endl;
}