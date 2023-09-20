#include <iostream>
#include<queue>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
      this->data = data;
      left = NULL;
      right = NULL;
    }

};

Node* builtTree() {
  int data;
  cout<<"Enter data"<<endl;
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

//inorder traversal

void inorderTraversal(Node* root) {
  if(root == NULL) {
    return;
  }

  //LNR
  //left part me jao
  inorderTraversal(root->left);
  //current node print kro
  cout<< root->data <<" ";
  //right part mein jao
  inorderTraversal(root->right);
}

//preorder traversal
void preorderTraversal(Node* root) {
  if(root == NULL) {
    return;
  }

  //NLR
   //current node print kro
  cout<< root->data <<" ";

  //left part me jao
  preorderTraversal(root->left);
 
  //right part mein jao
  preorderTraversal(root->right);
}

//post order traversal

void postorderTraversal(Node* root) {
  if(root == NULL) {
    return;
  }

  //LRN
  //left part me jao
  postorderTraversal(root->left);
 
  //right part mein jao
  postorderTraversal(root->right);

   //current node print kro
  cout<< root->data <<" ";
}

//height of tree
int height(Node* root) {
  if(root == NULL) {
    return 0;
  }

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  int ans = max(leftHeight, rightHeight) + 1;

  return ans;
}

//sum tree

int sumTree(Node* root) {
  if(root == NULL) 
    return 0;

  int leftSum = sumTree(root->left);
  int rightSum = sumTree(root->right);

  root->data = leftSum + root->data + rightSum;

  return root->data;
}

//kth Ancestor

bool kthAncestor(Node* root, int k, int p){
  if(root == NULL)
    return false;

  if(root->data == p)
    return true;
  
  bool leftAns = kthAncestor(root->left, k, p);
  bool rightAns = kthAncestor(root->right, k, p);

  if(leftAns || rightAns)
    k--;
  if(k == 0)
    cout<<"Answer is: "<<root->data<<endl;

  return leftAns || rightAns;
}

int main() {
 Node* root = NULL;

 root = builtTree();

 levelOrderTraversal(root);
 cout<<"answer found: "<<kthAncestor(root,1,3);
  return 0;
}