#include "iostream"
#include "vector"
using namespace std;


int solve(int n,vector<int> &dp) {
    if(n==0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int minOfWay=INT_MAX;
    for (int i = 1; i*i <=n ; ++i) {
        minOfWay = min(minOfWay,1 + solve(n-(i*i),dp));
    }
    return dp[n] = minOfWay;
}
int numSquares(int n) {
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int main(){
    cout<<numSquares(12);
}