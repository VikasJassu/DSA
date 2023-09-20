#include<iostream>
#include<stack>
#include<vector>

using namespace std;
vector<int> prevSmaller(vector<int> &v) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for(int i=0; i<v.size(); i++) {

        int curr = v[i];
        while(s.top() >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> &v) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for(int i= v.size()-1; i>=0; i--) {
        int curr = v[i];
        while(s.top() >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}


int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    
    vector<int> ans1 = nextSmaller(v);

    cout<<"Printing next smaller: "<<endl;
    for(auto i:ans1) {
        cout<< i << " ";
    } cout<<endl;

    vector<int> ans2 = prevSmaller(v);
    cout<<"Printing prev smaller: "<<endl;

    for(auto i: ans2) {
        cout<< i << " ";
    }
    cout<<endl;

}

//Time complexity is O(n);
// O(n) + O(n)