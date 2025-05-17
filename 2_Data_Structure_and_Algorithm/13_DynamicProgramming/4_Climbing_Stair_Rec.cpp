#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& cost,int index) {
    if(index >= cost.size()){
        return 0;
    }
    return cost[index] + min(solve(cost,index+1), solve(cost,index+2));
}

int minCostClimbingStairs(vector<int>& cost) {
    int fromZeothStair = solve(cost,0);
    int fromFirstStair = solve(cost,1);
    return min(fromFirstStair,fromZeothStair);
}

int main(){
    vector<int> cost = {10, 15, 20};
    cout<<minCostClimbingStairs(cost);
}