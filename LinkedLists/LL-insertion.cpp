#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node() {
            this->data = 0;
            this->next = NULL;
        }

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }

};

void insertAtHead(Node* &head , Node* &tail , int data) {
    //create a node
    Node* newNode = new Node(data);

    //attach newNode to head
    newNode->next = head;

    if(head == NULL) {
        tail = newNode;
    }

    //make newNode head
    head = newNode;
}

void insertAtTail(Node* &head , Node* &tail , int data) {
    //create a node
    Node* newNode = new Node(data);

    //attach new tail
    if(tail == NULL) {
        tail = newNode;
        head = newNode;
    }
    else {
        tail->next = newNode; 
    }
    

    //update tail
    
        tail = newNode;
    
}

void print(Node* head) {
    Node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
int main() 
{
    Node* head = NULL;
    Node* tail = NULL;

    // insertAtHead(head , tail , 10);
    // insertAtHead(head , tail , 20);
    // insertAtHead(head , tail , 30);
    // insertAtHead(head , tail , 40);
    // insertAtHead(head , tail , 50);
    insertAtTail(head , tail , 1);

    print(head);
}