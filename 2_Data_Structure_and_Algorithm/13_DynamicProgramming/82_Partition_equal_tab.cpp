#include "iostream"
#include "vector"

using namespace std;

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

    vector<vector<bool>> dp(n+1,vector<bool>(target+1, false));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int index = n-1; index >=0 ; --index) {
        for (int tar = 0; tar <= target; ++tar) {
            bool include = false;
            if(tar-nums[index] >= 0) {
                include = dp[index + 1][tar - nums[index]];
            }
            bool exclude = dp[index+1][tar];
            dp[index][tar] = include || exclude;
        }
    }
    return dp[0][target];
}

int main(){
    vector<int> nums = {1, 5, 11, 5};
    cout<<canPartition(nums);
}