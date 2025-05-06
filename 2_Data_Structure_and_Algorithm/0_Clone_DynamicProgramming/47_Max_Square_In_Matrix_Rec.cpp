#include "iostream"
#include "vector"
using namespace std;

int solve(vector<vector<char>>& matrix,int i,int j,int &globalMax) {
    if(i >= matrix.size() || j >= matrix[0].size()){
        return 0;
    }
    int rightMaxSize = solve(matrix,i+1,j,globalMax);
    int downMaxSize = solve(matrix,i,j+1,globalMax);
    int diagonalMaxSize = solve(matrix,i+1,j+1,globalMax);

    if(matrix[i][j] == '1'){
        int ans = 1 + min(rightMaxSize, min(downMaxSize, diagonalMaxSize));
        globalMax = max(globalMax, ans);
        return ans;
    }
    return 0;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int globalMax = INT_MIN;
    solve(matrix,0,0,globalMax);
    if(globalMax == INT_MIN){
        return 0;
    }
    return globalMax*globalMax;
}


int main(){

}