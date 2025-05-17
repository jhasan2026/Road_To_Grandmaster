#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums,int start,int end,vector<int> &dp) {

    dp[end] = nums[end];
    dp[end - 1] = max(nums[end], nums[end-1]);

    for (int i = end-2; i >=0 ; --i) {
        int include = nums[i] + dp[i+2];
        int exclude = 0 + dp[i+1];
        dp[i] = max(include,exclude);
    }
    return dp[start];

}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    if(n==2){
        return max(nums[0],nums[1]);

    }
    vector<int> dp(n+2,-1);
    int firstToSecLast = solve(nums,0,n-1,dp);
    int secToLast =  solve(nums,1,n-2,dp);
    return max(firstToSecLast,secToLast);
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    cout<<rob(nums);
}

