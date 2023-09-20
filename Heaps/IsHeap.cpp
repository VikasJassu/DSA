//given complete binary tree is heap or not
#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
        
};

Node* builtTree() {
        int data;
        cout<<"Enter Data: ";
        cin>>data;

        if(data == -1) {
            return NULL;
        }

        Node* root = new Node(data);
        cout<<"Enter data to insert in left of "<< data << " node"<<endl;
        root->left = builtTree();
        cout<<"Enter data to insert in right of "<< data << " node"<<endl;
        root->right = builtTree();

        return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL) {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }

}

//given CBT is heap or not
pair<bool, int> isHeap(Node* root) {
    if(root == NULL){
        pair<bool, int> p = make_pair(true, INT_MIN);
        return p;
    }
    if(root->left == NULL && root->right == NULL) {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isHeap(root->left);
    pair<bool, int> rightAns = isHeap(root->right);

    if(
        root->data > leftAns.second && root->data > rightAns.second && leftAns.first == true && rightAns.first == true
    ) {
         pair<bool,int> ans = make_pair(true, root->data); 
         return ans;
    }
    else{
        pair<bool,int> ans = make_pair(false, root->data); 
        return ans;
    }
}

void convertIntoInorder(Node* root, vector<int> &inorder) {
    if(root == NULL)
        return;
    convertIntoInorder(root->left, inorder);
    inorder.push_back(root->data);
    convertIntoInorder(root->right, inorder);

}

void convertIntoMaxHeap(Node* root, vector<int> &inorder, priority_queue<int> &q) {
    if(root == NULL)
        return;

    convertIntoMaxHeap(root->left,inorder,q);
    convertIntoMaxHeap(root->right,inorder,q);
    q.push(inorder[i]);
}

//Convert bst that is CBT into heap
void convertIntoHeap(Node* root) {
    if(root == NULL)
        return;
    
    priority_queue<int> q;
    //convert bst into inorder
    vector<int> inorder;
    convertIntoInorder(root, inorder);

    convertIntoMaxHeap(root,inorder,q);

    for(int i=0; i< inorder.size(); i++) {
       q.push(inorder[i]);
    }
    cout<<"printing heap:"<<endl;
    while(!q.empty()) {
        cout<<q.top()<<" ";
        q.pop();
    } cout<<endl;
}


int main()
{
    Node* root = NULL;
    root = builtTree();
    levelOrderTraversal(root);
    // pair<bool, int> ans = isHeap(root);
    // cout<<"Is CBT is Heap: "<<ans.first <<endl;

    convertIntoHeap(root);
    // cout<<"Max Heap:"<<endl;
    // levelOrderTraversal(root);
    
}