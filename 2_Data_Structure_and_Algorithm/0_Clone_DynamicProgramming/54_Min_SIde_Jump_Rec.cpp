#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& obstacles,int currLane,int currPos) {
    if(currPos == obstacles.size()){
        return 0;
    }
    if(currLane != obstacles[currPos+1]){
        return solve(obstacles,currLane,currPos+1);
    }
    else{
        int minSideJumpCost = INT_MAX;
        for (int lane = 1; lane <= 3 ; ++lane) {
            if(lane != currLane && lane != obstacles[currPos]){
                minSideJumpCost = min(minSideJumpCost, 1 + solve(obstacles,lane,currPos));
            }
        }
        return minSideJumpCost;
    }
}

int minSideJumps(vector<int>& obstacles) {
    return solve(obstacles,2,0);
}


int main(){
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout<<minSideJumps(obstacles);
}