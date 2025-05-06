#include "iostream"
#include "limits.h"
#include "vector"
#define MOD 1000000007
using namespace std;


long long int countDerangements(int n) {
    vector<long long int> dp(n+1,-1);

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i] = ((n-1)*(dp[i-1] + dp[i-2]))%MOD;        //(n-1)*(solution of sub problems)
                //(solution of sub problems)  --->  if we fix {0 at ith position}  and {ith value at 0 position) ->
                                                                        //two value is fixed....rest of the solution is f(x-2)
                                                 // if we fix only {0 at ith position} and we don't know {ith values position} ->
                                                                        //one value is fixed....rest of the solution is f(x-1)
    }

    return dp[n];
}


int main(){
    cout<<countDerangements(3);
}