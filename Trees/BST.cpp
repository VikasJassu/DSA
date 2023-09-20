#include<iostream>
#include<queue>
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

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<< temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
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

void inorderTraversal(Node* root) {
    if(root == NULL)
        return;

    //LNR
    inorderTraversal(root->left);
    cout<< root->data<<" ";
    inorderTraversal(root->right);
    
}

void preorderTraversal(Node* root) {
    if(root == NULL)
        return;

    //NLR
    cout<< root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
}

void postorderTraversal(Node* root) {
    if(root == NULL)
        return;

    //LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<< root->data<<" ";
    
}

//searching in BST
bool searchInBST(Node* root, int target) {
    if(root == NULL)
        return false;

    if(root->data == target) 
        return true;
    
    if(root->data > target) {
        return searchInBST(root->left, target);
    }
    else{
        return searchInBST(root->right, target);
    }

}

//searching in BST(it returns value)
// Node search(Node* root, int target) {
//     if(root == NULL)
//         return NULL;

//     if(root->data == target) 
//         return root->data;
    
//     if(root->data > target) {
//         return search(root->left, target);
//     }
//     else{
//         return search(root->right, target);
//     }

// }

//find minimum in BST

int minVal(Node* root) {
    Node* temp = root;
    if(temp == NULL)
        return -1;

    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

//find maximum in BST


int maxVal(Node* root) {
    Node* temp = root;
    if(temp == NULL)
        return -1;

    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

//delete node in BST

Node* deleteNodeInBST(Node* root, int target) {
    if(root == NULL)
        return NULL;

    if(root->data == target){
        //isme chaar conditions banegi
        //root have no child means a leaf node
        if(root->right == NULL && root->left == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL) {
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->left != NULL && root->right ==NULL) {
            Node* child = root->left;
            delete root;
            return child;
        }
        else{
            int inorderPre = maxVal(root->left);
            root->data = inorderPre;
            root->left = deleteNodeInBST(root->left, inorderPre);
            return root;
        }
    }

    else if(target > root->data) {
        //right side mein jao
        root->right = deleteNodeInBST(root->right,target);
    }
    else if(target < root->data){
        //abhi left side mein jao
        root->left = deleteNodeInBST(root->left,target);
    }
    return root;
}

//built bst using inorder

Node* builtBSTusingInorder(int inorder[], int s, int e) {
    if( s > e) {
        return NULL;
    }
    
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = builtBSTusingInorder(inorder, s, mid-1);
    root->right = builtBSTusingInorder(inorder, mid+1, e);

    return root;
}

//convert BST into Doubley linked list
//head ko by referance pass karna h (must keep in mind);
void convertIntoLL(Node* root, Node* &head) {
    if(root == NULL)
        return;

    convertIntoLL(root->right, head);
    root->right = head;
    if(head != NULL)
        head->left = root;
    head = root;

    convertIntoLL(root->left, head);
}

//converting LL into BST
Node* convertLLintoBST(Node* &head, int n) {
    if(n <= 0 || head == NULL)
        return NULL;

    //left subtree mein call kro
    Node* leftSubTree = convertLLintoBST(head, n-1-n/2);

    Node* root = head;
    root->left = leftSubTree;
    head = head->right; //ye line bhot important hai, maximum galti yahi hoti hai.

    root->right = convertLLintoBST(head, n/2);

    return root;

}

Node* mergeLL(Node* head1, Node* head2) {
    Node* first = head1;
    Node* second = head2;

    Node* head = NULL;

    if(first->data <= second->data) {
       Node* temp1 = first;
       first = first->right;
       head->right = temp1;
       temp1->left = head;
       temp1->right = NULL;
       first->left = NULL;
       head = head->right;
    }
    else{
       Node* temp = second;
       second = second->right;
       head->right = temp;
       temp->left = head;
       temp->right = NULL;
       second->left = NULL;
    }

    return head;

}

Node* mergeTwoBST(Node* root1, Node* root2) {
    if(root1 == NULL || root2 == NULL) {
        return NULL;
    }

    Node* head1 = NULL;
    Node* head2 = NULL;
     cout<<"hello ji"<<endl;
    convertIntoLL(root1, head1);

    convertIntoLL(root2, head2);
    print(head1);
    print(head2);
    Node* head = mergeLL(head1, head2);
    cout<<"hello ji"<<endl;
    
    Node* root = convertLLintoBST(head,14);
    return root;
}



Node* builtBST(Node* root, int data) {
    //if root is null it means tree is empty so insert first node
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(root->data > data) {
        root->left = builtBST(root->left,data);
    }
    else{
        root->right = builtBST(root->right,data);
    }

    return root;
}
void takeInput(Node* &root) {
    int data;
    cin>>data;

    while (data != -1)
    {
       root = builtBST(root,data);
       cin>>data;
    }

}


int main()
{
    Node* root1 = NULL;

    cout<<"Enter data: "<<endl;

    takeInput(root1);
    cout<<"Printing BST: "<<endl;
    levelOrderTraversal(root1);

    Node* root2 = NULL;
    cout<<"Enter data: "<<endl;

    takeInput(root2);
    cout<<"Printing BST: "<<endl;
    levelOrderTraversal(root2);

    Node* ans = mergeTwoBST(root1, root2);
    cout<<"Printing merged bst:"<<endl;
    levelOrderTraversal(ans);
    // int k = 1;

    // cout<<"Printing inorder Traversal"<<endl;
    // inorderTraversal(root);
    // cout<<endl;

    // cout<<"Printing preorder Traversal"<<endl;
    // preorderTraversal(root);
    // cout<<endl;

    // cout<<"Printing postorder Traversal"<<endl;
    // postorderTraversal(root);
    // cout<<endl;

    // cout<<"answer is: "<<searchInBST(root,k);

    // cout<<"Minimum is: "<<minVal(root)<<endl;
    // cout<<"Maximum is: "<<maxVal(root)<<endl;

    // deleteNodeInBST(root,100);

    // int inorder[] = {1,2,3,4,5,6,7,8,9};
    // int s = 0;
    // int e = 8;

    // Node* root = builtBSTusingInorder(inorder, s, e);

    // cout<<"Printing BST: "<<endl;
    // levelOrderTraversal(root);

    // Node* head = NULL;
    // convertIntoLL(root, head);
    // cout<<"Printing doubly Linked List: "<<endl;
    // print(head);

    // Node* root1 = NULL;
    // root1 = convertLLintoBST(head,9);
    // cout<<"Printing bst from LL:"<<endl;
    // levelOrderTraversal(root1);

}