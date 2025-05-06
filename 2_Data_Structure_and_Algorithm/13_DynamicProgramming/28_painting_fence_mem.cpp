#include "iostream"
#include "vector"
#define MOD 1000000007

using namespace std;

int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a,int b){
    return (a%MOD * 1LL * b%MOD)%MOD;
}

int solve(int n, int k,vector<int> &dp) {
    if(n == 1){                 //one fence can be paint with k colors
        return k;
    }
    if(n == 2){                     //two fence can be paint with (k + k*(k-1)) = k^2 colors
        return mul(k,k);
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = add(mul(k-1, solve(n-1,k,dp)),mul(k-1, solve(n-2,k,dp)));    //f(n) = (k-1) * { f(n-2) + f(n-1) }
                                                                                        //f(n-2) -> solution by last two combination
                                                                                        //f(n-1) -> solution by last three combination
}

int numberOfWays(int n, int k) {
    vector<int> dp(n+1,-1);
    return solve(n,k,dp);
}

int main(){
    cout<<numberOfWays(4,2);
}