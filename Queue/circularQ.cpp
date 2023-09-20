#include<iostream>
using namespace std;

class CirQueue{
    public:
            int *arr;
            int size;
            int front;
            int rear;


            CirQueue(int size) {
                this->size = size;
                arr = new int[size];
                front = -1;
                rear = -1;
            }

            void push(int data) {

                //Queue full
                //rear = (front-1) % (size-1) => iss ek condition se niche wali
                //dono conditions handle ho skti hai

                if((front == 0 && rear == size-1) || (front - rear == 1)) {
                    cout<<"Q is full, cannot push"<<endl;
                }
                //first element handle
                else if(front == -1) {
                    front = rear = 0;
                    arr[rear] = data;
                }

                //make circular queue
                else if(rear == size - 1 && front != 0) {
                    rear = 0;
                    arr[rear] = data;
                }
                //normal flow
                else{
                    rear++;
                    arr[rear] = data;
                }
            }

            void pop() {
                if(front == -1) {
                    cout<<"Q is empty , cannot pop"<<endl;
                }
                else if(front == rear) {
                    arr[front] = -1;
                    front = -1;
                    rear = -1;
                }
                else if(front == size - 1) {
                    front = 0;
                }
                else{
                    arr[front] = -1;
                    front++;
                }
            }

          void print() {
            for(int i=0; i<size; i++) {
                cout<<arr[i]<< " ";
            } cout<<endl;
          }
};

int main()
{
    CirQueue q(7);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.pop();
    q.pop();
    q.push(90);
    q.push(100);
    q.push(110);

    q.print();
    

}