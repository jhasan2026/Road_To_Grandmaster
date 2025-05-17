#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums,int currIndex,int prevIndex,vector<vector<int>> &dp) {
    if(currIndex >= nums.size()){
        return 0;
    }
    if(dp[currIndex][prevIndex+1] != -1){
        return dp[currIndex][prevIndex+1];
    }
    int include = 0;
    if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
        include = 1 + solve(nums,currIndex+1,currIndex,dp);
    }
    int exclude = 0 + solve(nums,currIndex+1,prevIndex,dp);
    return dp[currIndex][prevIndex+1] = max(include,exclude);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(nums,0,-1,dp);
}


int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums);
}