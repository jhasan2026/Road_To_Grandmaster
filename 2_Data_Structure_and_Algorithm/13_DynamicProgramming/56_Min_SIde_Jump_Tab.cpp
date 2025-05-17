#include "iostream"
#include "vector"
using namespace std;

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size()-1;
    vector<vector<int>> dp(4,vector<int>(n+1,INT_MAX));

    dp[0][n] =0;
    dp[1][n] =0;
    dp[2][n] =0;
    dp[3][n] =0;

    for (int currPos = n-1; currPos >= 0; --currPos) {
        for (int currLane = 1; currLane <= 3; ++currLane) {
            if(currLane != obstacles[currPos+1]){
                dp[currLane][currPos] = dp[currLane][currPos+1];
            }
            else{
                int minSideJump = INT_MAX;
                for (int lane = 1; lane <= 3; ++lane) {
                    if(lane!=currLane && lane!=obstacles[currPos]) {
                        minSideJump = min(minSideJump, 1 + dp[lane][currPos+1]);
                    }
                }
                dp[currLane][currPos] = minSideJump;
            }
        }
    }


    return dp[2][0];
}


int main(){
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout<<minSideJumps(obstacles);
}