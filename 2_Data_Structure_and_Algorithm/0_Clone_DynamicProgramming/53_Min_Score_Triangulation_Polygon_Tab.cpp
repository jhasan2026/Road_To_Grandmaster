#include "iostream"
#include "vector"
using namespace std;

int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for (int i = n-1; i >=0 ; --i) {
        for (int j = i+2; j <= n-1; ++j) {
            int minScore = INT_MAX;
            for (int k = i+1; k <= j-1 ; ++k) {
                minScore = min(minScore, values[i]*values[k]*values[j] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = minScore;
        }
    }
    return dp[0][n-1];
}

int main(){
    vector<int> values = {1, 2, 3};
    cout<<minScoreTriangulation(values);
}