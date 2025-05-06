#include "iostream"
#include "vector"

using namespace std;

bool solve(vector<int>& nums,int target,int index,vector<vector<int>> &dp) {
    if(index >= nums.size()){
        return false;
    }
    if(target < 0){
        return false;
    }
    if(target == 0){
        return true;
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    int include = solve(nums,target - nums[index],index+1,dp);
    int exclude = solve(nums,target,index+1,dp);
    return dp[index][target] = include || exclude;
}

bool canPartition(vector<int>& nums) {
    int sum=0;
    for (auto x:nums) {
        sum += x;
    }
    if(sum & 1){
        return false;
    }
    int target = sum/2;
    int n = nums.size();

    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

    return solve(nums,target,0,dp);
}

int main(){
    vector<int> nums = {1, 5, 11, 5};
    cout<<canPartition(nums);
}