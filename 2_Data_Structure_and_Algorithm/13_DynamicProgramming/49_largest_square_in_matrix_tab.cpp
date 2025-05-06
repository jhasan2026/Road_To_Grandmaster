#include "iostream"
#include "vector"

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int maxi = INT_MIN;
    int n=matrix.size() , m = matrix[0].size();
    vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));

    for (int i = n-1; i >= 0 ; --i) {
        for (int j = m-1; j >= 0 ; --j) {
            int rightSize = dp[i][j+1];         //get max from right
            int downSize = dp[i+1][j];              //get max from down
            int diagonalSize = dp[i+1][j+1];        //get max from Diagonal


            if(matrix[i][j] == '1'){            //if the element is 1
                int ans = 1 + min(rightSize,min(downSize,diagonalSize));    //get max by these three ways
                maxi = max(maxi , ans);
                dp[i][j] = ans;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    if(maxi == INT_MIN){
        return 0;
    }
    return maxi*maxi;
}

int main(){
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
//    matrix = {{'0'}};
    cout<<maximalSquare(matrix);
}