#include "iostream"
#include "vector"
using namespace std;

int solve(int n,vector<int> &dp) {
    if(n==0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int oneStairJump = solve(n-1,dp);
    int twoStairJump = solve(n-2,dp);
    return dp[n] = oneStairJump + twoStairJump;
}

int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}


int main(){
    cout<<climbStairs(3);
}