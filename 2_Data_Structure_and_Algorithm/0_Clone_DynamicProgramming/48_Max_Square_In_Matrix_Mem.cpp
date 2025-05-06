#include "iostream"
#include "vector"
using namespace std;

int solve(vector<vector<char>>& matrix,int i,int j,int &globalMax,vector<vector<int>> &dp) {
    if(i >= matrix.size() || j >= matrix[0].size()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int rightMaxSize = solve(matrix,i+1,j,globalMax,dp);
    int downMaxSize = solve(matrix,i,j+1,globalMax,dp);
    int diagonalMaxSize = solve(matrix,i+1,j+1,globalMax,dp);

    if(matrix[i][j] == '1'){
        int ans = 1 + min(rightMaxSize, min(downMaxSize, diagonalMaxSize));
        globalMax = max(globalMax, ans);
        return dp[i][j] = ans;
    }
    return dp[i][j] = 0;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int globalMax = INT_MIN;
    int n=matrix.size(),m=matrix[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));


    solve(matrix,0,0,globalMax,dp);
    if(globalMax == INT_MIN){
        return 0;
    }
    return globalMax*globalMax;
}


int main(){

}