#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));

    dp[0][0] = 1;
    for (int dice = 1; dice <= n; ++dice) {
        for (int tar = 1; tar <= target; ++tar) {
            long long ans = 0;
            for (int face = 1; face <= k; ++face) {
                if(tar-face >= 0) {
                    ans = ans + (dp[dice - 1][tar - face]) % MOD;
                }
            }
            dp[dice][tar] = ans%MOD;
        }
    }
    return dp[n][target]%MOD;
}

int main(){
    int n = 30, k = 30, target = 500;
    cout<<numRollsToTarget(n,k,target);
}

