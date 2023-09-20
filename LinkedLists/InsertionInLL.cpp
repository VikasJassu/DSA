#include <iostream>
using namespace std;

class Node{
        public:
                int data;
                Node* next;

                Node() {
                        this->data = 0;
                        this->next = NULL;
                        //Node* next = NULL bhi likh sakte hain
                }

                Node(int data) {
                        this->data = data;
                        this->next = NULL;
                }

                ~Node() {
                        cout<<this->data<<" is deleted"<<endl;
                }
};

void print(Node* &head) {
        Node* temp = head;
        while(temp != NULL) {
                cout<<temp->data<<" ";
                temp = temp->next;
        }
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

void insertAtHead(Node* &head , Node* &tail , int data) {

        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //creating newNode
        Node* newNode = new Node(data);

        //connect newNode->next to head
        newNode->next = head;

        //updating head
        // if(head == NULL) {
        //         tail = newNode;
        // }
        head = newNode;
}

void insertAtTail(Node* &head , Node* &tail , int data) {

        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //creating a newNode
        Node* newNode = new Node(data);

        //connecting 
        // if( tail == NULL) {
        //         tail = newNode;
        //         head = newNode;
        // }
        // else {
        //         tail->next = newNode;
        // }

        tail->next = newNode;

        //updating
        tail = newNode;
}

void insertAtMiddle(Node* &head , Node* &tail , int position , int data) {
        //check LL is empty or not
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }

        if(position == 0) {
                insertAtHead(head , tail , data);
                return;
        }

        int len = findLength(head);
        cout<<"length is: "<<len<<endl;
        if(position >= len) {
                insertAtTail(head , tail , data);
                return;
        }

        
        //find position where to insert

        int i = 1;
        Node* prev = head;
        while(i < position) {
                prev = prev->next;
                i++;
        }

        Node* curr = prev->next;

        //create new node

        Node* newNode = new Node(data);

        //current se connect kro

        newNode->next = curr;

        //previous se connect kro

        prev->next = newNode;
}

void deleteNode(Node* &head , Node* &tail , int position) {
        if(head == NULL) {
                cout<<"Cannot be deleted , LL is empty"<<endl;
                return;
        }

        //starting node

        if(position == 1) {
                //temp bnana hai
                Node* temp = head;

                //head ko shift kro
                head = head->next;

                //head ko de-attach kro
                temp->next = NULL;

                //delete
                delete temp;
                return;
        }

        //tail node delete
        int len = findLength(head);
        

        if(position == len) {
                int i = 1;
                Node* prev = head;
                while(i < position-1) {
                      prev = prev->next;
                      i++;
                }

                // prev->next = NULL;
                // Node* temp = tail;
                // tail = prev;
                // delete temp;
                
                //dono mein se konsa bhi order likh sakte hain deletion ka

                Node* temp = tail;
                prev->next = NULL;
                tail = prev;
                delete temp;
                return;
        }

         //beech ka element delete karna hai
                int i = 1;
                Node* prev = head;
                while(i < position-1) {
                        prev = prev->next;
                        i++;
                }

                Node* curr = prev->next;
                // prev->next = NULL;
                prev->next = curr->next;
                // curr->next = NULL; iski jrurat nhi h but babbar bhai ne likhvaya h.
                delete curr;

                return;

}

Node* reverse(Node* &prev , Node* &curr) {
        //base case
        if(curr == NULL) {
                return prev;
        }

        //ek case solve
        Node* forward = curr->next;
        curr->next = prev;

        //recursive call
        reverse(curr , forward);

}
int main() {

  Node* head = NULL;
  Node* tail = NULL;

//   Node* first = new Node(10);
//   Node* second = new Node(20);
//   Node* third = new Node(30);

//   first->next = second;
//   second->next = third;

  insertAtHead(head , tail , 40);
  insertAtHead(head , tail , 50);
  insertAtHead(head , tail , 60);
  insertAtHead(head , tail , 70);
  insertAtTail(head , tail , 100);
  insertAtTail(head , tail , 110);
  insertAtHead(head , tail , 80);

  print(head);
     cout<<endl;
//   cout<<"head: "<<head->data<<endl;
//   cout<<"tail: "<<tail->data<<endl;

//   insertAtMiddle(head , tail , 1 , 22);
//   print(head);
//   cout<<endl;
//   cout<<"head: "<<head->data<<endl;
//   cout<<"tail: "<<tail->data<<endl;

// deleteNode(head , tail , 3);
// print(head);

Node* prev = NULL;
Node* curr = head;
head = reverse(prev , curr);
cout<<"Reverse of Linked List"<<endl;
print(head);
  return 0;
}