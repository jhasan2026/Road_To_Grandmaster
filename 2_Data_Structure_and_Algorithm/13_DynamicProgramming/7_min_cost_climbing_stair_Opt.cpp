#include "iostream"
#include "vector"

using namespace std;


int minCostClimbingStairTab(vector<int> &cost){
    int totalStair = cost.size();
    int secondPrev = cost[0];   //0th cost is cost[0]

    int firstPrev = cost[1];     //1st cost is cost[1]

    for (int stairNo = 2; stairNo <totalStair ; ++stairNo) {
        int oneStepCost = cost[stairNo] + firstPrev;    //count that stairCost and calculate f(stairNo+1) cost
        int twoStepCost = cost[stairNo] + secondPrev;   //count that stairCost and calculate f(stairNo+2) cost
        int curr = min(oneStepCost,twoStepCost);        //min of them
        secondPrev = firstPrev;
        firstPrev = curr;
    }

    return min(firstPrev,secondPrev);       //min of solution starts from 0th stair 1st stair
}

int main(){
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<minCostClimbingStairTab(cost);
}