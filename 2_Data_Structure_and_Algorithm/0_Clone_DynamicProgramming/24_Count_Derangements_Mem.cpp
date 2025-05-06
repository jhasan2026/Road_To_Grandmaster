#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;

long long int solve(int n,vector<long long> &dp) {
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return  dp[n] = ((n-1)%MOD)*(solve((n-1)%MOD,dp) + solve((n-2)%MOD,dp))%MOD;
}

long long int countDerangements(int n) {
    vector<long long> dp(n+1,-1);
    return solve(n,dp);
}



int main(){
    cout<<countDerangements(4);
}