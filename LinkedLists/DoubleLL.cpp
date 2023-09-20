#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;


        Node() {
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }

        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }

        ~Node() {
            cout<< this->data <<" is deleted"<<endl;
        }
};


void print(Node* &head) {

    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int findLength(Node* head) {
    int len = 0;

    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head , Node* &tail , int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //create a Node
    Node* newNode = new Node(data);

    //attach newNode to head
    newNode->next = head;

    //head a prev newNode se connect kro
    head->prev = newNode;

    //head update
    head = newNode;

}

void insertAtTail(Node* &head , Node* &tail , int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //create a Node
    Node* newNode = new Node(data);

    //tail ko newNode se connect kro
    tail->next = newNode;

    //newNode ka prev tail se connect kro
    newNode->prev = tail;

    //update tail
    tail = newNode;
}

void insertAtPosition(Node* &head , Node* &tail , int data , int position) {

    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position <= 1) {
        insertAtHead(head,tail,data);
        return;
    }

    int len = findLength(head);
    if(position > len) {
        insertAtTail(head,tail,data);
        return;
    }

    //insert at middle

    int i = 1;
    Node* prevNode = head;
    while(i < position-1) {
        prevNode = prevNode->next;
        i++;
    }

    // Node* curr = prevNode->next;

    //create a node
    Node* newNode = new Node(data);

    //all steps to insert
    // prevNode->next = newNode;
    // newNode->prev = prevNode;
    // curr->prev = newNode;
    // newNode->next = curr;

    //without current ka use kre

    prevNode->next->prev = newNode;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

}

void deleteFromPos(Node* &head , Node* &tail , int position) {
    if(head == NULL) {
        cout<<"Your Linked List is empty"<<endl;
        return;
    }

    if(head->next == NULL) {
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);
    if(position > len) {
        cout<<"Enter a valid position"<<endl;
        return;
    }

    if(position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;
    }
    // int len = findLength(head);
    if(position == len) {
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    int i = 1;
    Node* left = head;
    while(i < position - 1) {
        left = left->next;
        i++;
    }

    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
    return;
}
int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = first;
    Node* tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;


    // print(first);
    // cout<<endl;
    // int len = findLength(first);
    // cout<<"length is: "<<len<<endl;
    // cout<<"After insertion :"<<endl;

    // insertAtHead(head,tail,111);
    // insertAtTail(head , tail , 222);
    // insertAtPosition(head,tail,99,2);
    // print(head);
    

    deleteFromPos(head , tail , 5);
    print(head);
}