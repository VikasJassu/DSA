#include<iostream>
#include<cmath>
using namespace std;
int decimalToBinaryMethod1(int n) {
    int ans = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = n%2;
        ans = bit * pow(10, i++) + ans;
        n = n/2;      
    }
    return ans;   
}

int decimalToBinaryMethod2(int n) {
    int ans = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = n & 1;
        ans = bit * pow(10,i++) + ans;
        n = n >> 1;
    }
    return ans;
}

int binaryToDecimal(int n) {
    int ans = 0;
    int i = 0;
    while (n > 0)
    {
       int bit = n & 1;
       ans = ans + bit * pow(2, i++);
       n = n/10;
    }
    return ans;
    
}
int main()
{
    int n = 1100;
    int ans = binaryToDecimal(n);
    cout<<"ans: "<<ans<<endl; 
}