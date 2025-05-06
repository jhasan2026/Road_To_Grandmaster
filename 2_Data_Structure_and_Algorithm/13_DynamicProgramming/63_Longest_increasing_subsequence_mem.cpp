#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums,int curr,int prev,vector<vector<int>> &dp) {
    if(curr == nums.size()){
        return 0;
    }

    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }

    int include = 0;
    if(prev==-1 || nums[curr] > nums[prev]) {                      //if the number is first-one or the number is greater than previous one:: take it
       include = 1 + solve(nums, curr+1,curr,dp);
    }
    int exclude = 0 + solve(nums,curr+1,prev,dp);
    return dp[curr][prev+1] = max(include,exclude);
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