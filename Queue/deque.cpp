//deque is doubly queue, we can insert and pop from both sides
#include<iostream>
using namespace std;

class deque{
    public:
            int *arr;
            int size;
            int front;
            int rear;

            deque(int size) {
                this->size = size;
                arr = new int[size];
                front = -1;
                rear = -1;
            }

            void pushRear(int data) {
                if((rear == size-1 && front == 0) || (front - rear == 1)) {
                    cout<<"Deque is full, cannot push"<<endl;
                }
                else if(front == -1) {
                    front = rear = 0;
                    arr[rear] = data;
                }
                else if(rear == size-1 && front != 0) {
                    rear = 0;
                    arr[rear] = data;
                }
                else{
                    rear++;
                    arr[rear] = data;
                }
            }
            void pushFront(int data) {
                if((rear == size-1 && front == 0) || (front - rear == 1)) {
                    cout<<"Deque is full,cannot push"<<endl;
                }
                else if(front == -1) {
                    front = rear = 0;
                    arr[front] = data;
                }
                //circular queue
                else if(front == 0 && rear != size-1) {
                    front = size-1;
                    arr[front] = data;
                }
                else{
                    front--;
                    arr[front] = data;
                }
            }

            void popFront(){
                if(front == -1) {
                    cout<<"Q is empty, cannot pop"<<endl;
                }
                else if(front == rear) {
                    arr[front] = -1;
                    front = -1;
                    rear = -1;
                }
                else if(front == size-1){
                    arr[front] = -1;
                    front = 0;
                }
                else{
                    arr[front] = -1;
                    front++;
                }
            }

            void popRear() {
                if(rear == -1) {
                    cout<<"Q is full cannot pop"<<endl;
                }
                else if(front == rear) {
                    arr[rear] = -1;
                    front = -1;
                    rear = -1;
                }
                else if(rear == 0) {
                    arr[rear] = -1;
                    rear = size - 1;
                }
                else {
                    arr[rear] = -1;
                    rear--;
                }

            }

           
            void print() {
            cout<<"Front:"<<arr[front]<<endl;
            cout<<"Rear:"<<arr[rear]<<endl;
            for(int i=0; i<size; i++) {
                cout<<arr[i]<< " ";
            } cout<<endl;
            }
        
};
int main() {
    deque dq(7);
    // dq.pushRear(10);
    // dq.pushFront(20);
    // dq.pushRear(30);
    // dq.pushFront(40);
    // dq.popFront();
    // dq.popRear();
    // dq.popRear();
    // dq.popFront();
    // dq.popFront();
    // dq.pushFront(100);
    // dq.pushRear(200);
    // dq.pushFront(300);
    // dq.pushFront(400);
    // dq.pushFront(500);
    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushRear(30);
    dq.pushRear(40);
    dq.pushRear(50);
    dq.pushRear(60);
    dq.pushRear(70);
    dq.popRear();
    dq.popRear();
    dq.popRear();
    dq.pushFront(100);
    dq.pushFront(200);
    dq.pushFront(300);
    dq.pushFront(400);
    dq.popFront();



    dq.print();
}