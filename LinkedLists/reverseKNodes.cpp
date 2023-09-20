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

Node* reverse(Node* &head , int k) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    int len = findLength(head);
    if(k > len) {
        return head;
    }

    //reverse first k-nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;
    while(count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL) {
        head->next = reverse(forward , k); // yaha pr forward ki jagah curr bhi use ho skta hai
    }

    return prev;
}
int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    // Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // fifth->next = sixth;

    print(head);
    cout<<"length of LL is "<< findLength(head)<<endl;
    head = reverse(head,3);
    print(head);
}