#include "iostream"
#include "vector"
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (auto num:nums) {
        sum += num;
    }
    if(sum%2 == 1){
        return false;
    }
    vector<vector<int>> dp(n+1,vector<int>(sum/2+1,0));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int index = n-1; index >=0 ; --index) {
        for (int target = 1; target <= sum/2; ++target) {
            int include = 0;
            if(target - nums[index] >=0) {
                include = dp[index + 1][target - nums[index]];
            }
            int exclude = dp[index+1][target];
            dp[index][target] =  include || exclude;
        }
    }

    return dp[0][sum/2];

}


int main(){
    vector<int> nums = {1, 5, 11, 5};
    cout<<canPartition(nums);
}