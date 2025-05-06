#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int> &cost,int stairNo){

    if(stairNo >= cost.size()){     //if the last stair
        return 0;
    }

    int oneStepCost = cost[stairNo] + solve(cost,stairNo+1);   //count that stairCost and calculate f(stairNo+1) cost


    int twoStepCost = cost[stairNo] + solve(cost,stairNo+2);  //count that stairCost and calculate f(stairNo+2) cost


    return min(oneStepCost,twoStepCost);  //min of them
}

int minCostClimbingStair(vector<int> &cost){

    int startFromFirstStair = solve(cost,0);    //get cost starts from 0th.....nth

    int startFromSecondStair = solve(cost,1);    //get cost starts from 1st.....nth

    return min(startFromFirstStair,startFromSecondStair);   // min among them
}

int main(){
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<minCostClimbingStair(cost);
}