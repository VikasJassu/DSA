//rod ke maximum pieces kitne kar sakte hain using given length of pieces i.e x,y,z & n is length of rod.
#include<iostream>
#include<limits.h>
using namespace std;

int solve(int n, int x, int y, int z) {
    if(n==0) {
        return 0;
    }
    if(n<0) {
        return INT_MIN;
    }

    int a = solve(n-x,x,y,z) + 1;
    int b = solve(n-y,x,y,z) + 1;
    int c = solve(n-z,x,y,z) + 1;

    int ans = max(a, max(b,c));
    return ans;
}
int main() 
{
    int n = 10;
    int x = 3;
    int y = 2;
    int z = 1;

    int answer = solve(n,x,y,z);
    if(answer < 0) {
        answer = 0;
    }
    
    cout<<"answer is: "<<answer<<endl;
}
