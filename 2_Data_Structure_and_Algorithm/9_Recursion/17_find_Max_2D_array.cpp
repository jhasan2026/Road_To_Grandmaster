#include "iostream"
#include "vector"

using namespace std;

int findMax2DArr(int n,int m,vector<vector<int>> &matrix,int i,int j){
    if(i>=n || j>=m){
        return INT_MIN;
    }
    if(i==n-1 && j==m-1){
        return matrix[i][j];
    }
    int rightMax = findMax2DArr(n,m,matrix,i,j+1);
    int downMax = findMax2DArr(n,m,matrix,i+1,j);
    int diagonalMax = findMax2DArr(n,m,matrix,i+1,j+1);
    return max(matrix[i][j], max(rightMax,max(downMax,diagonalMax)));
}

int main(){
    vector<vector<int>> matrix={
            {19,92,38,4},
            {5,96,73,88},
            {34,46,75,91}
    };
    cout<<findMax2DArr(3,4,matrix,0,0);
}