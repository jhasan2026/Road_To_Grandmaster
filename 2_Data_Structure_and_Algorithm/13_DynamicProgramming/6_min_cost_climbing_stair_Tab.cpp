#include "iostream"
#include "vector"

using namespace std;


int minCostClimbingStairTab(vector<int> &cost){
    int totalStair = cost.size();
    vector<int> dp(totalStair+1 , 0);

    dp[0] = cost[0];    //0th cost is cost[0]
    dp[1] = cost[1];    //1st cost is cost[1]

    for (int stairNo = 2; stairNo <totalStair ; ++stairNo) {
        int oneStepCost = cost[stairNo] + dp[stairNo-1];    //count that stairCost and calculate f(stairNo+1) cost
        int twoStepCost = cost[stairNo] + dp[stairNo-2];    //count that stairCost and calculate f(stairNo+2) cost
        dp[stairNo] = min(oneStepCost,twoStepCost);     //min of them
    }

    return min(dp[totalStair-1],dp[totalStair-2]);          //min of solution starts from 0th stair 1st stair
}

int main(){
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<minCostClimbingStairTab(cost);
}