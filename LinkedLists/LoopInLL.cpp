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

//LOOP PRESENT OR NOT
bool isLoop(Node* &head) {
    if(head == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }

            if(slow == fast) {
                return true;
            }
    }
    return false;
}

//STARTING POINT OF LOOP

Node* startingPoint(Node* &head) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast) {
            slow = head;
            break;
        }
    }
    
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    return slow;
}


//REMOVE LOOP

Node* removeLoop(Node* &head){
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast) {
            slow = head;
            break;
        }
    }

    Node* prev = fast;
    while(slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
    return head;;
}

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);
    Node* tenth = new Node(100);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = fifth;

// cout<<"Loop is present or not: "<<isLoop(head)<<endl;
// cout<<"Starting point of Loop is: "<<startingPoint(head)->data<<endl;
head = removeLoop(head);
print(head);
cout<<"Loop is present or not: "<<isLoop(head)<<endl;

}