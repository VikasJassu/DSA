#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }

};

void print(Node* &head) {
    Node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int findLength(Node* &head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

bool isCircular(Node* &head) {
    if(head == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast) {
            return true;
        }
    }
    return false;
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);
    Node* tenth = new Node(100);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = first;


    cout<<"LL is circular or not: "<<isCircular(first)<<endl;



}