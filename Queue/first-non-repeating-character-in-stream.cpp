#include<iostream>
#include<queue>
#include<string>



using namespace std;

int main()
{
    string s = "aac";
   
    int freq[26] = {0};
    queue<char> q;
    string ans = "";

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];

        //frequency update kro
        freq[ch - 'a']++;
        q.push(ch);

        //pop kro repeating alphabet ko
        while(!q.empty()) {
            if(freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()) {
            ans.push_back('#');
        }
    }
    
    cout<<"Answer is: "<<ans<<endl;
}