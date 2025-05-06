#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& obstacles,int currLane,int currPos,vector<vector<int>> &dp) {
    if(currPos == obstacles.size()){                      //stop here
        return 0;
    }

    if(dp[currLane][currPos] != -1){
        return dp[currLane][currPos];
    }


    if(currLane != obstacles[currPos+1]){                            // move forward only
        return dp[currLane][currPos] = solve(obstacles,currLane,currPos+1,dp);         //get solution from next position
     }
    else{
        int minSideJump = INT_MAX;
        for (int lane = 1; lane <= 3; ++lane) {
            if(lane!=currLane && lane!=obstacles[currPos]) {          //if it is jump to own place and there is a obstacle
                minSideJump = min(minSideJump, 1 + solve(obstacles, lane,
                                                         currPos+1,dp));  // 1 jump and solution for rest of the path (which lane is minimum)
            }
        }
        return dp[currLane][currPos] = minSideJump;
    }
}

int minSideJumps(vector<int>& obstacles) {
    vector<vector<int>> dp(4,vector<int>(obstacles.size()+1,-1));

    return solve(obstacles,2,0,dp);                //starting from 2nd lane and 0th position
}

int main(){
    vector<int> obstacles = {0, 0, 2, 0};
    cout<<minSideJumps(obstacles);
}