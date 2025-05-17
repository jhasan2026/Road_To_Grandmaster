#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[0][0] = 1;
    for (int dice = 1; dice <= n; ++dice) {
        for (int tar = 1; tar <= target; ++tar) {
            int noOfWays = 0;
            for (int face = 1; face <= k; ++face) {
                if(tar-face >= 0) {
                    int temp = dp[dice-1][tar-face]%MOD;
                    noOfWays += temp;
                    noOfWays = noOfWays%MOD;
                }
            }
            dp[dice][tar] = noOfWays;
        }
    }
    return dp[n][target];
}

int main(){
    int n = 2, k = 6, target = 7;
    cout<<numRollsToTarget(n,k,target);
}