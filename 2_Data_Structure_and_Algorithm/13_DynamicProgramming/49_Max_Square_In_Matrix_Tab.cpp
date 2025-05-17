#include "iostream"
#include "vector"
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int globalMax = INT_MIN;
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int rightMaxSize = dp[i + 1][j];
            int downMaxSize = dp[i][j + 1];
            int diagonalMaxSize = dp[i + 1][j + 1];

            if (matrix[i][j] == '1') {
                int ans = 1 + min(rightMaxSize,min(downMaxSize, diagonalMaxSize));
                globalMax = max(globalMax, ans);
                dp[i][j] = ans;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    if(globalMax == INT_MIN){
        return 0;
    }
    return globalMax*globalMax;
}


int main(){

}