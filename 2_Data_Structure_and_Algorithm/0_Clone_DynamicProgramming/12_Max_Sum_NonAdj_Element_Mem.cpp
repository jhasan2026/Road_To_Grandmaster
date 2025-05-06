#include "iostream"
#include "vector"
#include <cstring>
using namespace std;

int solve(vector<int>& nums,int index,vector<int> &dp) {
    if(index >= nums.size()){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int include = nums[index] + solve(nums,index+2,dp);
    int exclude = 0 + solve(nums,index+1,dp);
    return dp[index] = max(include,exclude);
}


long long maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
    long long sum = 0;
    vector<int> dp(nums.size()+1,-1);

    for (int i = 0; i < queries.size(); ++i) {
        nums[queries[i][0]] = queries[i][1];
        sum += solve(nums,0,dp);
        memset(dp.data(), -1, dp.size() * sizeof(int));
    }
    return sum;
}

int main(){
    vector<int> nums = {4, 0, -1, -2, 3, 1, -1};
    vector<vector<int>> queries = {{3,1},
                                   {0,-2},
                                   {1,-1},
                                   {0,-2},
                                   {5,4},
                                   {6,-3},
                                   {6,-2},
                                   {2,-1}};;

    cout<<maximumSumSubsequence(nums,queries);
}