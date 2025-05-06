#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

int longestArithSeqLength(vector<int>& nums) {
    int n=nums.size();
    if(n <= 2){               //1 element array have AP size 1 and 2 element have 2 size
        return n;
    }

    unordered_map<int,int> dp[n+1];
    int ans=0;
    for (int index = 1; index < n; ++index) {
        for (int prev = 0; prev < index; ++prev) {
            int diff = nums[index] - nums[prev];
            int cnt=1;

            if(dp[prev].count(diff)){
                cnt = dp[prev][diff];
            }

            dp[index][diff] = 1 + cnt;
            ans = max(ans, dp[index][diff]);
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {20, 1, 15, 3, 10, 5, 8};
    cout<<longestArithSeqLength(nums);
}