#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveUsingRec(int n, int k) {
    if( n == 1) {
        return k;
    }
    if(n == 2) {
        return k*k;
    }
    int ans = (solveUsingRec(n-1, k) + solveUsingRec(n-2, k))*(k-1);
    return ans;
}

int memoisationSol(int n, int k, vector<int> &dp) {
    if( n == 1) {
        return k;
    }
    if(n == 2) {
        return k*k;
    }
    if(dp[n] != -1)
        return dp[n];

    dp[n] = (memoisationSol(n-1, k, dp) + memoisationSol(n-2, k, dp))*(k-1);
    return dp[n];
}
int tabulationSol(int n, int k){
    vector<int> dp(n+1, INT_MIN);

    dp[1] = k;
    dp[2] = k*k;

    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    }
    return dp[n];
}

int main()
{
    int n = 4;
    int k = 3;
    vector<int> dp(n+1, -1);
    int ans = solveUsingRec(n, k);
    cout<<"Answer using Recursion: "<<ans<<endl;
    int ans1 = memoisationSol(n, k, dp);
    cout<<"Answer using memoisation: "<<ans1<<endl;
    int ans2 = tabulationSol(n, k);
    cout<<"Answer using tabulation: "<<ans2<<endl;
    
}