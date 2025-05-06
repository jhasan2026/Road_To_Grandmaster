#include "iostream"
#include "vector"

using namespace std;

bool isPrime(int n,int i){
    if(n==1){
        return false;
    }
    if(i==n){
        return true;
    }
    if(n%i==0){
        return false;
    }
    return isPrime(n,i+1);
}

int countPrime(int n,int m,vector<vector<int>> &matrix,int i,int j){
    if(i>=n || j>=m){
        return 0;
    }
    if(i==n-1 && j==m-1){
        if(isPrime(matrix[i][j],2)){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(isPrime(matrix[i][j],2)){
        return 1 + countPrime(n,m,matrix,i+1,j) +countPrime(n,m,matrix,i,j+1) +countPrime(n,m,matrix,i+1,j+1);
    }
    else{
        return 0 + countPrime(n,m,matrix,i+1,j) +countPrime(n,m,matrix,i,j+1) +countPrime(n,m,matrix,i+1,j+1);
    }
}

int main(){
    vector<vector<int>> matrix={
            {19,92,38,4},
            {5,96,73,88},
            {34,46,75,91}
    };
    cout<<countPrime(3,4,matrix,0,0);
}