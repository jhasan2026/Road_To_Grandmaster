#include "iostream"
#include "vector"
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for (int curr = n-1; curr >= 0; --curr) {
        for (int prev = curr-1; prev >= -1 ; --prev) {
            int include = 0;
            if(prev==-1 || nums[curr] > nums[prev]) {                      //if the number is first-one or the number is greater than previous one:: take it
                include = 1 + dp[curr+1][curr+1];
            }
            int exclude = 0 + dp[curr+1][prev+1];
            dp[curr][prev+1] = max(include,exclude);
        }
    }

    return dp[0][0];
}

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums);
}