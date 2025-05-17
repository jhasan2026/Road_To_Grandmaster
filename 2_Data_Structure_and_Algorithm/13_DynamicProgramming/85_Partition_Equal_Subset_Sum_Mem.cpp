#include "iostream"
#include "vector"
using namespace std;

bool solve(vector<int>& nums,int index,int target,vector<vector<int>> &dp) {
    if(index >= nums.size()){
        return false;
    }
    if(target < 0){
        return false;
    }
    if(target == 0){
        return true;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    int include = solve(nums,index+1,target-nums[index],dp);
    int exclude = solve(nums,index+1,target,dp);
    return dp[index][target] =  include || exclude;
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (auto num:nums) {
        sum += num;
    }
    if(sum%2 == 1){
        return false;
    }
    vector<vector<int>> dp(n+1,vector<int>(sum/2+1,-1));
    return solve(nums,0,sum/2,dp);

}


int main(){
    vector<int> nums = {1, 5, 11, 5};
    cout<<canPartition(nums);
}