#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;


long long combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);

    dp[0] = 1;

    for (int tar = 1; tar <= target; ++tar) {
        long long totalNoOfWays = 0;
        for (auto num : nums) {
            if (tar - num >= 0) {
                totalNoOfWays += (dp[tar - num]%MOD);
            }
        }
        dp[tar] = totalNoOfWays;
    }
    return dp[target];
}


int main(){
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout<<combinationSum4(nums,target);
}