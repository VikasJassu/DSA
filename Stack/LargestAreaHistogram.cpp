#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>

using namespace std;
vector<int> prevSmaller(vector<int> &v) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for(int i=0; i<v.size(); i++) {

        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> &v) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());

    for(int i= v.size()-1; i>=0; i--) {
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


int getRectangleHistogramArea(vector<int> &height) {
    
    vector<int> nextSmall = nextSmaller(height);

    vector<int> prevSmall = prevSmaller(height);
    int maxArea = INT_MIN;
    int size = height.size();

    for(int i=0; i < height.size(); i++) {
        int length = height[i];
        if(nextSmall[i] == -1) {
            nextSmall[i] = size;
        }
        int width = nextSmall[i] - prevSmall[i] - 1;

        
        int area = length * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    vector<int> height;

    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);

    cout<<"Max area is: "<<getRectangleHistogramArea(height);

}