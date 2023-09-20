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

Node* findMiddle(Node* &head) {
    Node* slow = head;
    Node* fast = head->next; //isko fast = head bhi likh sakte hain
    //agar LL mein nodes even hai to fast = head->next likh sakte hain
    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
   return slow;
}

Node* reverse(Node* &head) {
        if(head == NULL) {
                cout<<"LL is empty"<<endl;
                return NULL;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* forward = curr->next;

        while(curr != NULL) {
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
        }
        return prev;
}

bool isPalindrome(Node* &head) {
        if(head == NULL) {
                cout<<"LL is empty"<<endl;
                return true;
        }

        if(head->next == NULL) {
                return true;
        }

        Node* mid = findMiddle(head);

        mid->next = reverse(mid->next);

        Node* temp1 = head;
        Node* temp2 = mid->next;


        while(temp2 != NULL) {
                if(temp1->data != temp2->data) {
                        return false;
                }
                else {
                        temp1 = temp1->next;
                        temp2 = temp2->next;
                }
        }

        return true;
}
int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(30);
    Node* fifth = new Node(20);
    Node* sixth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

        print(head);
        cout<<"LL is Palindrome or not: "<<isPalindrome(head)<<endl;
}