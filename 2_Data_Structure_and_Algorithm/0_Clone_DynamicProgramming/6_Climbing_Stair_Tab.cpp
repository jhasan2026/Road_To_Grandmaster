#include "iostream"
#include "vector"
using namespace std;


int minCostClimbingStairs(vector<int>& cost) {
    int n= cost.size();
    vector<int> dp(n+1,0);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int index = 2; index <n  ; ++index) {
        dp[index] = cost[index] + min(dp[index-1], dp[index-2]);
    }

    return min(dp[n-1],dp[n-2]);
}

int main(){
    vector<int> cost = {0,0,0,0};
    cout<<minCostClimbingStairs(cost);
}