#include<iostream>
#include<vector>
using namespace std;

void checkKey(string str , int n , int i , char key , vector<int>& ans, int& count) {
    if(i>=n) {
         return;
    }
   

    if(str[i] == key) {
        count++;
        ans.push_back(i);
    } 

    return checkKey(str,n,i+1,key,ans,count);
}
int main()
{
    string str = "vikasJassu";
    int n = str.length();
    int i = 0;
    char key = 's';
    vector<int> ans;
    int count = 0;
    checkKey(str, n, i, key, ans, count);
    cout<<"key is found "<<count<<" times"<<endl;
    cout<<"printing answer: "<<endl;

    for( auto val: ans) {
        cout<<val <<" ";
    }
    cout<<endl;
}