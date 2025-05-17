#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums,int start,int end,vector<int> &dp) {
    if(start >= end){
        return 0;
    }
    if(dp[start] != -1){
        return dp[start];
    }
    int include = nums[start] + solve(nums,start+2,end,dp);
    int exclude = 0 + solve(nums,start+1,end,dp);
    return dp[start] = max(include,exclude);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1,-1);
    int firstToSecLast = solve(nums,0,n,dp);
    int secToLast =  solve(nums,1,n-1,dp);
    return max(firstToSecLast,secToLast);
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    cout<<rob(nums);
}

