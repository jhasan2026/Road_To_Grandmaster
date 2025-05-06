#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int>& values,int i,int j,vector<vector<int>> &dp) {
    if(i+1 == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int mini = INT_MAX;
    for (int k = i+1; k <= j-1; ++k) {                          //from i+1.......j-1  (second one to secLast one)   -> k is an intermediate state {angle <ikj>}
        mini = min(mini, values[i]*values[j]*values[k] + solve(values,i,k,dp) + solve(values,k,j,dp));          //sol = i*j*k + f(i,k) + f(k,j)
    }
    return dp[i][j] = mini;
}

int minScoreTriangulation(vector<int>& values) {
    int n=values.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(values,0,n-1,dp);
}

int main(){
    vector<int> values = {1, 3, 1, 4, 1, 5};
    cout<<minScoreTriangulation(values);
}