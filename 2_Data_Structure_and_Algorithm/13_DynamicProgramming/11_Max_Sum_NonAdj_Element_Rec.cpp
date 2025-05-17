#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums,int index) {
    if(index >= nums.size()){
        return 0;
    }
    int include = nums[index] + solve(nums,index+2);
    int exclude = 0 + solve(nums,index+1);
    return max(include,exclude);
}


int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
    int sum = 0;
    for (int i = 0; i < queries.size(); ++i) {
        nums[queries[i][0]] = queries[i][1];
        sum += solve(nums,0);
    }
    return sum;
}

int main(){
    vector<int> nums = {0, 3, 3, 3, 1, -2};
    vector<vector<int>> queries = {{4, 0},
                                   {1, 0}};

    cout<<maximumSumSubsequence(nums,queries);
}