#include "iostream"
#include "limits.h"
#include "vector"
#define MOD 1000000007
using namespace std;


long long int solve(int n,vector<long long int> &dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = ((n-1)%MOD)*(solve((n-1)%MOD,dp) + solve((n-2)%MOD,dp))%MOD;     //(n-1)*(solution of sub problems)
              //(solution of sub problems)  --->  if we fix {0 at ith position}  and {ith value at 0 position) ->
                                                                                //two value is fixed....rest of the solution is f(x-2)
                                                // if we fix only {0 at ith position} and we don't know {ith values position} ->
                                                                //one value is fixed....rest of the solution is f(x-1)
}


long long int countDerangements(int n) {
    vector<long long int> dp(n+1,-1);
    return solve(n,dp);
}


int main(){
    cout<<countDerangements(3);
}