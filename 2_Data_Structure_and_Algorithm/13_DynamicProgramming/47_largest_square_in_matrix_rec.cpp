#include "iostream"
#include "vector"

using namespace std;

int solve(vector<vector<char>>& matrix,int i,int j,int &maxi) {
    if(i>=matrix.size() || j>=matrix[0].size()){        //either i and j is out from the size of row and col
        return 0;
    }
    int rightSize = solve(matrix,i,j+1,maxi);       //get max from right
    int downSize = solve(matrix,i+1,j,maxi);            //get max from down
    int diagonalSize = solve(matrix,i+1,j+1,maxi);      //get max from Diagonal


    if(matrix[i][j] == '1'){                                    //if the element is 1
        int ans = 1 + min(rightSize,min(downSize,diagonalSize));  //get max by these three ways
        maxi = max(maxi , ans);
        return ans;
    }
    return 0;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int maxi = INT_MIN;
    solve(matrix,0,0,maxi);
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