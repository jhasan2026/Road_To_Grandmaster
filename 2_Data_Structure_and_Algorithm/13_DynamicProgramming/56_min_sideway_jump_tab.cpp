#include "iostream"
#include "vector"
using namespace std;


int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<vector<int>> dp(4,vector<int>(n+1,INT_MAX));

    dp[0][n] =0;
    dp[1][n] =0;
    dp[2][n] =0;
    dp[3][n] =0;

    for (int currPos = n-1; currPos >= 0; --currPos) {
        for (int currLane = 1; currLane <= 3; ++currLane) {
            if(currLane != obstacles[currPos+1]){                            // move forward only
                dp[currLane][currPos] = dp[currLane][currPos+1];         //get solution from next position
            }
            else{
                int minSideJump = INT_MAX;
                for (int lane = 1; lane <= 3; ++lane) {
                    if(lane!=currLane && lane!=obstacles[currPos]) {          //if it is jump to own place and there is a obstacle
                        minSideJump = min(minSideJump, 1 + dp[lane][currPos+1]);  // 1 jump and solution for rest of the path (which lane is minimum)
                    }
                }
                dp[currLane][currPos] = minSideJump;
            }
        }
    }


    return dp[2][0];                //starting from 2nd lane and 0th position
}

int main(){
    vector<int> obstacles = {0, 0, 2, 0};
    cout<<minSideJumps(obstacles);
}