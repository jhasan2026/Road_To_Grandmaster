#include "iostream"
#include "vector"
#define MOD 100000007
using namespace std;

int mul(int a,int b){
    return (a%MOD * 1LL * b%MOD)%MOD;
}

int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}


int solve(int n, int k,vector<int> &dp) {
    if(n==1){
        return k;
    }
    if(n==2){
        return k + (k*(k-1));
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = mul((k-1), add(solve(n-1,k,dp), solve(n-2,k,dp)) );
}
int numberOfWays(int n, int k) {
    vector<int> dp(n+1,-1);
    return solve(n,k,dp);
}

int main(){
    cout<<numberOfWays(234, 532);
}