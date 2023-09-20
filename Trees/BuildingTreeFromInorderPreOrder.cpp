#include<iostream>
#include<queue>
#include<unordered_map>
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

void levelOrderTraversal(Node* root) {
  queue<Node*> q;

  q.push(root);
  q.push(NULL);

  //loop chlao jab tak queue empty na ho jay
  while(!q.empty()) {
    Node* temp = q.front();
    //pop kro
    q.pop();

    //check whether temp is null or not
    if(temp == NULL) {
      cout<<endl;
      if(!q.empty()) {
        q.push(NULL);
      }
    }
    else{
      //print temp data
    cout<< temp->data<<" ";
    //insert child of node
    if(temp->left) {
      q.push(temp->left);
    }
    if(temp->right) {
      q.push(temp->right);
    }
    }
    
  }
}

//yaha pe position find out kr rhe hai O(n) time mein but isko optimise kiya ja sakta hai map ka use karke
//inorder and preorder array ko map use karke pehle hi store kra la to O(1) mein ho jayega ye.
int search(int arr[],int root, int size) {
    for(int i=0; i<size; i++) {
       if(arr[i] == root ) {
        return i;
       } 
    }
    return -1;
}

void createMapping(unordered_map<int,int> &mapping,int inorder[],int n) {
  for(int i=0; i<n; i++) {
    mapping[inorder[i]] = i;
  }
}

Node* builtTreeFromInorderPreorder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd) {
    if(preIndex >= size || inorderStart > inorderEnd) {
        return NULL;
    }

    //step Ist
    int element = preorder[preIndex++]; //++ nhi bhulna hai very important hai

    Node* root = new Node(element);
    //search root in inorder
    int position = search(inorder,element,size);

    //root->left solve kro
    root->left = builtTreeFromInorderPreorder(inorder,preorder,size,preIndex,inorderStart,position-1);

    //root->right solve kro
    root->right = builtTreeFromInorderPreorder(inorder,preorder,size,preIndex,position+1,inorderEnd);

    return root;
   
}

Node* builtTreeFromInorderPostorder(int inorder[], int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd,unordered_map<int,int> &mapping) {
  if(postIndex < 0 || inorderStart > inorderEnd) {
    return NULL;
  } 

  //step 1 root nikalo
  int element = postorder[postIndex--];

  Node* root = new Node(element);

  // int position = search(inorder,element,size);
  int position = mapping[element];

  //issme pehle right side mein jana hai
  root->right = builtTreeFromInorderPostorder(inorder,postorder,size,postIndex,position + 1,inorderEnd,mapping);

  root->left = builtTreeFromInorderPostorder(inorder,postorder,size,postIndex,inorderStart,position - 1,mapping);

  return root;
}
int main()
{
    // int inorder[] = {40,20,50,10,60,30,70};
    // int preorder[] = {10,20,40,50,30,60,70};
    // int size = 7;
    // int inorderStart = 0;
    // int inorderEnd = size - 1;
    // int preIndex = 0;

    // Node* root = builtTreeFromInorderPreorder(inorder,preorder,size,preIndex,inorderStart,inorderEnd);

    // cout<<"Printing tree: "<<endl;

    int inorder[] = {40,20,10,50,30,60};
    int postorder[] = {40,20,50,60,30,10};
    int size = 6;
    int inorderStart = 0;
    int inorderEnd = size - 1;
    int postIndex = size - 1;

    unordered_map<int,int>mapping;
    createMapping(mapping,inorder,size);
    
    Node* root = builtTreeFromInorderPostorder(inorder,postorder,size,postIndex,inorderStart,inorderEnd,mapping);
    cout<<"Printing tree: "<<endl;
    levelOrderTraversal(root);
}