#include<iostream>
#include<queue>
#include<map>
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


void topView(Node* root) {
    if(root == NULL)
        return;

    //create map to store hd and node->data
    map<int, int> topNode;

    queue< pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //check in map for hd any entry found or not
        if(topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

    
        if(frontNode->left) 
            q.push(make_pair(frontNode->left, hd-1));

        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }

     cout<<"Printing: "<<endl;
        for(auto i: topNode) {
            cout<< i.first << "-> "<<i.second<<endl;
        } 
}

void bottomView(Node* root) {

  if(root == NULL) 
    return;

  map<int, int> bottomNode;

  queue< pair<Node*, int>> q;
  q.push(make_pair(root,0));

  while(!q.empty()) {
    pair<Node*, int> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second;

    bottomNode[hd] = frontNode->data;

   if(frontNode->left) {
    q.push(make_pair(frontNode->left,hd-1));
   }

   if(frontNode->right){
    q.push(make_pair(frontNode->right,hd+1));
   }

  }

    cout<<"Printing: "<<endl;
        for(auto i: bottomNode) {
            cout<< i.first << "-> "<<i.second<<endl;
        } 
}

void leftView(Node* root, vector<int> &ans, int level) {
  if(root == NULL)
    return;

  if( level == ans.size()) {
    ans.push_back(root->data);
  }

  //left
  leftView(root->left, ans, level+1);
  //right
  leftView(root->right, ans, level+1);

}

void rightView(Node* root, vector<int> &ans, int level) {
  if(root == NULL) {
    return;
  }

  if(level == ans.size()) {
    ans.push_back(root->data);
  }

  //isme pehle right ki call karni hai
  rightView(root->right, ans, level+1);
  //left 
  rightView(root->left, ans, level+1);

}

void leftBoundary(Node* root) {
  if(root == NULL) 
    return;

  if(root->left == NULL && root->right == NULL)
    return; 

  cout<<root->data<<" ";

  if(root->left) 
    leftBoundary(root->left);

  else
    leftBoundary(root->right);
}

void leafNodes(Node* root) {
   if(root == NULL) 
    return;

   if(root->left == NULL && root->right == NULL){
    cout<<root->data<<" ";
   }
      
    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundary(Node* root) {
  if(root == NULL) 
    return;

  if(root->left == NULL && root->right == NULL)
    return;

  if(root->right) 
    rightBoundary(root->right);

 else
    rightBoundary(root->left);

  cout<<root->data<<" ";

}
void boundaryTraversal(Node* root) {
  if(root == NULL) 
    return;

  cout<< root->data<<" ";  

  //left side print kro
  leftBoundary(root->left);
  //leaf nodes print kro
  leafNodes(root);
  //right side print kro
  rightBoundary(root->right);

}
int main()
{
    Node* root = builtTree();
    // vector<int> ans;
    // int level = 0;
    // rightView(root,ans,level);

    // cout<<"Printing ans"<<endl;
    // for(auto i: ans) {
    //   cout<< i <<" ";
    // } cout<<endl;

    boundaryTraversal(root);
}