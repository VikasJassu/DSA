#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d) {
            this->data = d;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word) {
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    //first character insert kro
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    //character agar present h phle se then
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    //recursion
    insertWord(child, word.substr(1));
}

bool search(TrieNode* root, string word) {
    if(word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    //present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else{
        return false;
    }

    return search(child, word.substr(1));
}

void deleteNode(TrieNode* root, string word) {
   
    if(word.length() == 0) {
        root->isTerminal = false;
        return;
    }
       
    if(search(root, word)) {
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //word present
        child = root->children[index];
        deleteNode(child, word.substr(1));
    } 
    else{
        cout<<"word is absent "<<endl;
        return;
    }

   
}

int main()
{
    TrieNode* root = new TrieNode('-');

    insertWord(root, "code");
    insertWord(root, "coder"); 
    insertWord(root, "codehelp"); 
    insertWord(root, "codeforce");  
    insertWord(root, "vikas"); 
    insertWord(root, "vikasjassu"); 
    insertWord(root, "vikaskumar");
    deleteNode(root, "coder");

    if(search(root, "coder")) {
        cout<<"present "<<endl;
    } 
    else{
        cout<<"absent "<<endl;
    }
}