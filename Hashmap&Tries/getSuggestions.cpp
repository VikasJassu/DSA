#include<iostream>
#include<vector>
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

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

void storeSuggestions(TrieNode* curr, vector<string> &temp, string &prefix) {
    if(curr->isTerminal) {
        temp.push_back(prefix);
    }

    for(char ch='a'; ch<='z'; ch++){
        int index = ch - 'a';

        TrieNode* next = curr->children[index];
        if(next != NULL) {
            prefix.push_back(ch);
            storeSuggestions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}
vector<vector<string>> getSuggestions(TrieNode* root, string input) {
    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for(int i=0; i<input.length(); i++) {
        char lastch = input[i];
        int index = lastch - 'a';

        TrieNode* curr = prev->children[index];

        if(curr == NULL) {
            break;
        }
        else{
            vector<string> temp;
            prefix.push_back(lastch);
            storeSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}

int main()
{
    vector<string> v{
        "love",
        "lover",
        "loving",
        "lovely",
        "lost",
        "last",
        "lane",
        "local"
    };
    
    string input = "lovi";
    TrieNode* root = new TrieNode('-');
    for(int i=0; i<v.size(); i++){
        insertWord(root, v[i]);
    }

    vector<vector<string>> ans = getSuggestions(root, input);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<< ans[i][j] <<",";
        }
        cout<<endl;
    }

}