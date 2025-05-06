#include "iostream"
#include "vector"

using namespace std;

int solve(int n,vector<int> &dp){
    //    Oth fib is 0 and 1st is 1
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    //    f(x) = f(x-1) + f(x-2)
    return dp[n] = solve(n-1,dp) + solve(n-2,dp);
}

int fibonacciNumberMem(int n){
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int main(){
    cout<<fibonacciNumberMem(6);
}