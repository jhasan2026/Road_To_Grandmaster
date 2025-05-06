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
    int minScore = INT_MAX;
    for (int k = i+1; k <= j-1 ; ++k) {
        minScore = min(minScore, values[i]*values[k]*values[j] + solve(values,i,k,dp) + solve(values,k,j,dp));
    }
    return dp[i][j] = minScore;
}
int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(values,0,n-1,dp);
}

int main(){
    vector<int> values = {1, 2, 3};
    cout<<minScoreTriangulation(values);
}