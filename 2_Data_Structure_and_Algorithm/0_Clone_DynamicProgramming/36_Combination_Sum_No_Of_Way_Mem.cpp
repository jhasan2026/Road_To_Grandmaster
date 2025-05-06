#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums, int target,vector<int> &dp) {
    if(target < 0){
        return 0;
    }
    if(target == 0){
        return 1;
    }
    if(dp[target] != -1){
        return dp[target];
    }

    int totalNoOfWays = 0;
    for (auto num:nums) {
        totalNoOfWays += solve(nums,target-num,dp);
    }
    return dp[target] =  totalNoOfWays;
}
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1,-1);
    return solve(nums,target,dp);
}


int main(){
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout<<combinationSum4(nums,target);
}