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

//this approach is usually denied by interviewer
void sortZeroOneTwos(Node* &head) {
        int zero = 0;
        int one = 0;
        int two = 0;

        Node* temp = head;
        while(temp != NULL) {
                if(temp->data == 0) {
                        zero++;
                }
                else if(temp->data == 1) {
                        one++;
                }
                else if(temp->data == 2) {
                        two++;
                }
                temp = temp->next;
        }

        temp = head;
       
                while(zero--) {
                        temp->data = 0;
                        temp = temp->next;
                }
                while(one--) {
                        temp->data = 1;
                        temp = temp->next;
                }
                while(two--) {
                        temp->data = 2;
                        temp = temp->next;
                }
        
}

//this is good aproach 
Node* Sort2(Node* &head) {
        if(head == NULL) {
                cout<<"LL is empty"<<endl;
                return NULL;
        }

        if(head->next == NULL) {
                return head;
        }

        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;

        Node* oneHead = new Node(-1);
        Node* oneTail =  oneHead;

        Node* twoHead = new Node(-1);
        Node* twoTail =  twoHead;

        Node* curr = head;
        while(curr != NULL) {
                if(curr->data == 0) {
                        Node* temp = curr;
                        curr = curr->next;
                        temp->next = NULL;
                        zeroTail->next = temp; 
                        zeroTail = temp;
                }
                else if(curr->data == 1) {
                        Node* temp = curr;
                        curr = curr->next;
                        temp->next = NULL;
                        oneTail->next = temp;
                        oneTail = temp; 
                }
                else if(curr->data == 2) {
                        Node* temp = curr;
                        curr = curr->next;
                        temp->next = NULL;
                        twoTail->next = temp;
                        twoTail = temp;
                }
                
        }

        Node* temp = oneHead;
        oneHead = oneHead->next;
        temp->next = NULL;
        delete temp;

        temp = twoHead;
        twoHead = twoHead->next;
        temp->next = NULL;
        delete temp;

        if(oneHead != NULL) {
                zeroTail->next = oneHead;
                if(twoHead != NULL) {
                        oneTail->next = twoHead;
                }
        }
        else {
                if(twoHead != NULL) {
                        zeroTail->next = twoHead;
                }
        }

        temp = zeroHead;
        zeroHead = zeroHead->next;
        temp->next = NULL;
        delete temp;

        return zeroHead;
}

int main()
{
    Node* head = new Node(2);
    Node* second = new Node(0);
    Node* third = new Node(0);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);
    Node* sixth = new Node(0);
    Node* seventh = new Node(1);
    Node* eighth = new Node(0);
    Node* ninth = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = NULL;

    print(head);
//     sortZeroOneTwos(head);
//     print(head);
        Node* temp = NULL;
       head = Sort2(head);
        print(head);
}