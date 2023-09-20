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

        ~Node() {
                cout<<this->data<<" is deleted from LL"<<endl;
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

Node* reverse(Node* &head) {

        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL) {
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
}

Node* Sum(Node* &head1 , Node* &head2) {

        if(head1 == NULL)
                return head2;
        if(head2 == NULL) 
                return head1;
      
        Node* temp1 = reverse(head1);
        Node* temp2 = reverse(head2);
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        int carry = 0;

        while(temp1 != NULL && temp2 != NULL) {
                int sum = carry + temp1->data + temp2->data;
                int digit = sum%10;
                carry = sum/10;

                Node* newNode = new Node(digit);
                
                if(ansHead == NULL) {
                        ansHead = newNode;
                        ansTail = newNode;
                }
                else {
                        ansTail->next = newNode;
                        ansTail = newNode;
                }

                temp1 = temp1->next;
                temp2 = temp2->next;
        }

        while(temp1 != NULL) {
                int sum = carry + temp1->data;
                int digit = sum%10;
                carry = sum/10;
                Node* newNode = new Node(digit);
                ansTail->next = newNode;
                ansTail = newNode;
                temp1 = temp1->next;
        }

        while(temp2 != NULL) {
                int sum = carry + temp2->data;
                int digit = sum%10;
                carry = sum/10;
                Node* newNode = new Node(digit);
                ansTail->next = newNode;
                ansTail = newNode;
                temp2 = temp2->next;
        }

        while(carry != 0) {
                int sum = carry;
                int digit = sum%10;
                carry = sum/10;
                Node* newNode = new Node(digit);
                ansTail->next = newNode;
                ansTail = newNode;
        }

        Node* newAns = reverse(ansHead);
        return newAns;
}


int main()
{
    Node* head1 = new Node(9);
    Node* second1 = new Node(9);
    head1->next = second1;
    second1->next = NULL;


    Node* head2 = new Node(9);
    Node* second2 = new Node(9);
    Node* third2 = new Node(9);
    head2->next = second2;
    second2->next = third2;
    third2->next = NULL;

    print(head1);
    print(head2);

    Node* ans = Sum(head1 , head2);

    print(ans);
}