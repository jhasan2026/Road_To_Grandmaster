#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& obstacles,int currLane,int currPos) {
    if(currPos == obstacles.size()){                      //stop here
        return 0;
    }

    if(currLane != obstacles[currPos+1]){                            // move forward only
        return solve(obstacles,currLane,currPos+1);         //get solution from next position
     }
    else{
        int minSideJump = INT_MAX;
        for (int lane = 1; lane <= 3; ++lane) {
            if(lane!=currLane && lane!=obstacles[currPos]) {          //if it is jump to own place and there is a obstacle
                minSideJump = min(minSideJump, 1 + solve(obstacles, lane,
                                                         currPos));  // 1 jump and solution for rest of the path (which lane is minimum)
            }
        }
        return minSideJump;
    }
}

int minSideJumps(vector<int>& obstacles) {
    return solve(obstacles,2,0);                //starting from 2nd lane and 0th position
}

int main(){
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout<<minSideJumps(obstacles);
}