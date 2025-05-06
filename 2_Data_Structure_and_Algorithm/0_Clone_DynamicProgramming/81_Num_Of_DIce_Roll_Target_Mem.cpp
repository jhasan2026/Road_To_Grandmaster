#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;

int solve(int dice, int k, int target,vector<vector<int>> &dp) {
    if(target < 0){
        return 0;
    }
    if(target != 0 && dice==0){
        return 0;
    }
    if(target == 0 && dice==0){
        return 1;
    }
    if(target == 0 && dice!=0){
        return 0;
    }

    if(dp[dice][target] != -1){
        return dp[dice][target];
    }

    int noOfWays = 0;
    for (int face = 1; face <= k; ++face) {
        if(target-face >= 0) {
            int temp = solve(dice - 1, k, target - face, dp)%MOD;
            noOfWays += temp;
            noOfWays = noOfWays%MOD;
        }
    }
    return dp[dice][target] = noOfWays;
}
int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    return solve(n,k,target,dp);
}

int main(){
    int n = 2, k = 6, target = 7;
    cout<<numRollsToTarget(n,k,target);
}