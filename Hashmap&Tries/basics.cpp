#include <iostream>
#include<unordered_map>
using namespace std;

int main()
{   
    string s = "tiruvanathapuram";
    unordered_map<char, int> freq;
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        freq[ch]++;
    }
    for(auto i: freq) {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}