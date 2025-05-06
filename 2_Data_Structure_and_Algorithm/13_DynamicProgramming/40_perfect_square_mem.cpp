#include "iostream"
#include "vector"
using namespace std;

int solve(int n,vector<int> &dp){
    if(n==0){           //condition is satisfied -> return with sum 0
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int minCounter = n;
    for (int i = 1; i*i <= n; ++i) {
        minCounter = min(minCounter,1 +solve(n-i*i,dp));        //1 for that step and rest of the solution is f(n - i^2)
    }
    return dp[n] = minCounter;
}

int numSquares(int n) {
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int main(){
    cout<<numSquares(12);
}