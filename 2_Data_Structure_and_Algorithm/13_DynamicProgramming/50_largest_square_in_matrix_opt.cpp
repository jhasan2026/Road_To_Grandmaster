#include "iostream"
#include "vector"

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int maxi = INT_MIN;
    int n=matrix.size() , m = matrix[0].size();

    vector<int> curr(m+1,0);
    vector<int> next(m+1,0);
    for (int i = n-1; i >= 0 ; --i) {
        for (int j = m-1; j >= 0 ; --j) {
            int rightSize = curr[j+1];      //get max from right
            int downSize = next[j];         //get max from down
            int diagonalSize = next[j+1];       //get max from Diagonal


            if(matrix[i][j] == '1'){            //if the element is 1
                int ans = 1 + min(rightSize,min(downSize,diagonalSize));    //get max by these three ways
                maxi = max(maxi , ans);
                curr[j] = ans;
            }
            else{
                curr[j] = 0;
            }
        }
        next = curr;
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