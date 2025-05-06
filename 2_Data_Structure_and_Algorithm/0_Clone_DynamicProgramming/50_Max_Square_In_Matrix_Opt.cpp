#include "iostream"
#include "vector"
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int globalMax = INT_MIN;
    int n = matrix.size(), m = matrix[0].size();

    vector<int>curr (m + 1, 0);
    vector<int>next (m + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int rightMaxSize = next[j];
            int downMaxSize = curr[j + 1];
            int diagonalMaxSize = next[j + 1];

            if (matrix[i][j] == '1') {
                int ans = 1 + min(rightMaxSize,min(downMaxSize, diagonalMaxSize));
                globalMax = max(globalMax, ans);
                curr[j] = ans;
            } else {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    if(globalMax == INT_MIN){
        return 0;
    }
    return globalMax*globalMax;
}


int main(){

}