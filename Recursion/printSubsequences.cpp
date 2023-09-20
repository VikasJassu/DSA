#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(string str, string output, int i, vector<string>& v) {
    int size = str.length();
    if(i>= size) {
      //  cout<< output << endl;
    v.push_back(output);
        return;
    }

    printSubsequences(str, output, i+1, v);

    output.push_back(str[i]);
    // output = output + str[i]; aise bhi likh sakte h ans push_back bhi use kar sakte h.
    //ya printSubsequence(str, output + str[i], i+1, v); bhi use kar sakte h and iss ko exclude function se pehle likh sakte hain..
    printSubsequences(str, output, i+1, v);
    

}
int main()
{
    string str = "abc";
    string output = "";
    vector<string> v;
     int i = 0;
    printSubsequences(str, output, i,v);

for(string val: v) {
    cout<<val <<" ";
}
cout<<endl;
cout<<"size of output is "<<v.size()<<endl;
}