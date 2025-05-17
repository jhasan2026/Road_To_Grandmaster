#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& obstacles,int currLane,int currPos,vector<vector<int>> &dp) {
    if(currPos == obstacles.size()-1){
        return 0;
    }

    if(dp[currLane][currPos] != -1){
        return dp[currLane][currPos];
    }


    if(currLane != obstacles[currPos+1]){
        return solve(obstacles,currLane,currPos+1,dp);
    }
    else{
        int minSideJumpCost = INT_MAX;
        for (int lane = 1; lane <= 3 ; ++lane) {
            if(lane != currLane && lane != obstacles[currPos]){
                minSideJumpCost = min(minSideJumpCost, 1 + solve(obstacles,lane,currPos,dp));
            }
        }
        return dp[currLane][currPos] = minSideJumpCost;
    }
}

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<vector<int>> dp(4,vector<int>(n+1,-1));
    return solve(obstacles,2,0,dp);
}


int main(){
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout<<minSideJumps(obstacles);
}