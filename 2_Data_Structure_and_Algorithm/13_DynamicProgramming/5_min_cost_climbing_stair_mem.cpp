#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int> &cost,int stairNo,vector<int> &dp){
    if(stairNo >= cost.size()){     //if the last stair
        return 0;
    }
    if(dp[stairNo] != -1){
        return dp[stairNo];
    }
    int oneStepCost = cost[stairNo] + solve(cost,stairNo+1,dp);     //count that stairCost and calculate f(stairNo+1) cost
    int twoStepCost = cost[stairNo] + solve(cost,stairNo+2,dp);     //count that stairCost and calculate f(stairNo+2) cost
    return dp[stairNo] = min(oneStepCost,twoStepCost);       //min of them
}

int minCostClimbingStairMem(vector<int> &cost){
    int totalStair = cost.size();
    vector<int> dp(totalStair+1 , -1);
    int startFromFirstStair = solve(cost,0,dp);     //get cost starts from 0th.....nth
    int startFromSecondStair = solve(cost,1,dp);    //get cost starts from 1st.....nth
    return min(startFromFirstStair,startFromSecondStair);       // min among them
}

int main(){
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<minCostClimbingStairMem(cost);
}