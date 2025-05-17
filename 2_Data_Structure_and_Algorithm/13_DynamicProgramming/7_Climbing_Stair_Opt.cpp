#include "iostream"
#include "vector"
using namespace std;


int minCostClimbingStairs(vector<int>& cost) {
    int n= cost.size();


    int secondPrev = cost[0];
    int firstPrev = cost[1];

    for (int index = 2; index <n  ; ++index) {
        int curr = cost[index] + min(firstPrev, secondPrev);
        secondPrev = firstPrev;
        firstPrev =curr;
    }

    return min(firstPrev,secondPrev);
}

int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout<<minCostClimbingStairs(cost);
}