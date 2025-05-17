#include "iostream"
#include "vector"
using namespace std;

int solve(int dice, int k, int target) {
    if(target < 0){
        return 0;
    }
    if(target != 0 && dice==0){
        return 0;
    }
    if(target == 0 && dice==0){
        return 1;
    }
    if(target == 0 && dice!=0){
        return 0;
    }
    int noOfWays = 0;
    for (int face = 1; face <= k; ++face) {
        noOfWays += solve(dice-1,k,target-face);
    }
    return noOfWays;
}
int numRollsToTarget(int n, int k, int target) {
    return solve(n,k,target);
}

int main(){
    int n = 2, k = 6, target = 7;
    cout<<numRollsToTarget(n,k,target);
}