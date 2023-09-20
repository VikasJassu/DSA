#include<iostream>
#include<vector>
using namespace std;

int recursiveSol(int W, int wt[], int val[], int index){
       if(index == 1){
           if(wt[0] <= W){
               return val[0];
           }
           else{
            return 0;
           }
       }
       int include = 0;
       if(wt[index] <= W){
           include = val[index] + recursiveSol(W-wt[index], wt, val, index-1); 
       }
       
       int exclude = 0 + recursiveSol(W, wt, val, index-1);
       return max(include, exclude);
       
}
int memoisation(int W, int wt[], int val[], int index, vector<vector<int>> &dp){
       if(index == 0){
           if(wt[0] <= W){
               return val[0];
           }
           else return 0;
       }
       
       if(dp[index][W] != -1)
            return dp[index][W];
            
       int include = 0;
       if(wt[index] <= W){
           include = val[index] + memoisation(W-wt[index], wt, val, index-1, dp); //yha pr val[index] add karna bhul sakta hu
       }
       int exclude = 0;
       exclude = 0 + memoisation(W, wt, val, index-1, dp);
       dp[index][W] = max(include, exclude);
       return dp[index][W];
       
}

int tabulation(int W, int wt[], int val[], int index) {
    vector<vector<int>> dp(index, vector<int>(W+1, 0));

    for(int i=wt[0]; i<=W; i++) {
        if(wt[0] <= W){
               dp[0][i] = val[0];
           }
           else dp[0][i] = 0;
    } 

    for(int i=1; i<index; i++) {
        for(int j=0; j<=W; j++) {
            int include = 0;
            if(wt[i] <= j){
                include = val[i] + dp[i-1][j-wt[i]]; 
            }
            int exclude = 0;
            exclude = 0 + dp[i-1][j];
            cout<<"include:"<<include<<endl;
            cout<<"exclude:"<<exclude<<endl;
            cout<<dp[1][77]<<endl;
            dp[i][j] = max(include, exclude); 
            cout<<dp[1][77]<<endl;
        }
    }
    // cout<<"dp[index-1][W-1]"<<dp[index-1][W-3]<<endl;
    return dp[index-1][W]; // iss line me galti hoti h jrur

}

int spaceOptimisation(int W, int wt[], int val[], int index) {
    vector<int> prev(W+1, 0);
    vector<int> curr(W+1, 0);

    for(int i=wt[0]; i<=W; i++) {
        if(wt[0] <= W){
               prev[i] = val[0];
           }
           else prev[i] = 0;
    } 

    for(int i=1; i<index; i++) {
        for(int j=0; j<=W; j++) {
            int include = 0;
            if(wt[i] <= j){
                include = val[i] + prev[j-wt[i]]; 
            }
            int exclude = 0;
            exclude = 0 + prev[j];
            curr[j] = max(include, exclude); 
        }
        prev = curr; //yhi pr galti hoti hai
    }
    return prev[W]; // iss line me galti hoti h jrur

}

int bestSpaceOptimisation(int W, int wt[], int val[], int index) {
    vector<int> curr(W+1, 0);

    for(int i=wt[0]; i<=W; i++) {
        if(wt[0] <= W){
               curr[i] = val[0];
           }
           else curr[i] = 0;
    } 

    for(int i=1; i<index; i++) {
        for(int j=W; j>=0; j--) {
            int include = 0;
            if(wt[i] <= j){
                include = val[i] + curr[j-wt[i]]; 
            }
            int exclude = 0;
            exclude = 0 + curr[j];
            curr[j] = max(include, exclude); 
        }
    }
    return curr[W]; // iss line me galti hoti h jrur

}
int main()
{
    int W =78;
    int wt[] = {61,18};
    int val[] = {94,85};
    int n = 2;

    // vector<vector<int>> dp(n, vector<int>(W+1, -1));

    // int ans = memoisation(W,wt,val,n-1,dp);
    int ans = bestSpaceOptimisation(W,wt,val,n);
    cout<<"Printing ans: "<<ans<<endl;

}