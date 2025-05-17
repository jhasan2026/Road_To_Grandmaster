#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

int solve(vector<int>& nums,int index,int diff,unordered_map<int,int> dp[]) {

    if(index < 0){
        return 0;
    }

    if(dp[index].count(diff)){
        return dp[index][diff];
    }

    int ans = 0;
    for (int previousIndex = index-1; previousIndex >=0 ; --previousIndex) {
        if(nums[index] - nums[previousIndex] == diff){
            ans = max(ans, 1 + solve(nums,previousIndex,diff,dp));
        }
    }
    return dp[index][diff] =  ans;
}


int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2){
        return n;
    }
    unordered_map<int,int> dp[n+1];

    int ans = INT_MIN;
    for (int index = 0; index < n; ++index) {
        for (int j = index+1; j < n; ++j) {
            ans = max(ans, 2 + solve(nums,index,nums[j] - nums[index],dp));
        }
    }
    return ans;
}


int main(){
    vector<int> nums = {9,4,7,2,10};
    cout<<longestArithSeqLength(nums);
}