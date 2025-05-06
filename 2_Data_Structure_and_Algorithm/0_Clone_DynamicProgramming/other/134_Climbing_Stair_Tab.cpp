#include "iostream"
#include "vector"
using namespace std;

int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int oneStairJump = dp[i - 1];
        int twoStairJump = dp[i - 2];
        dp[i] = oneStairJump + twoStairJump;
    }
    return dp[n];
}


int main(){
    cout<<climbStairs(3);
}