#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;

long long solve(int dice, int k, int target, vector<vector<long long>>& dp) {
    if (target < 0) {
        return 0;
    }
    if (dice == 0 && target != 0) {
        return 0;
    }
    if (target == 0 && dice != 0) { // there is not 0 type face
        return 0;
    }
    if (dice == 0 && target == 0) { // one way :: nothing to do
        return 1;
    }

    if (dp[dice][target] != -1) {
        return dp[dice][target];
    }

    long long ans = 0;
    for (int face = 1; face <= k; ++face) {
        ans = ans + solve(dice - 1, k, target - face, dp)%MOD;
    }
    return dp[dice][target] = ans;
}
long long numRollsToTarget(int n, int k, int target) {
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
    return solve(n, k, target, dp)%MOD;
}

int main(){
    int n = 30, k = 30, target = 500;
    cout<<numRollsToTarget(n,k,target);
}

//222616187