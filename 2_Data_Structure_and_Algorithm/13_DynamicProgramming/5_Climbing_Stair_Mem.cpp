#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& cost,int index,vector<int> &dp) {
    if(index >= cost.size()){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    return dp[index] = cost[index] + min(solve(cost,index+1,dp), solve(cost,index+2,dp));
}

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1,-1);
    int fromZeothStair = solve(cost,0,dp);
    int fromFirstStair = solve(cost,1,dp);
    return min(fromFirstStair,fromZeothStair);
}

int main(){
    vector<int> cost = {10, 15, 20};
    cout<<minCostClimbingStairs(cost);
}