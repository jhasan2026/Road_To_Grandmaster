#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int solve(vector<int>& nums, vector<vector<int>>& queries,int index) {
    if(index >= nums.size()){
        return 0;
    }

    int include = nums[index] + solve(nums,queries,index+2);
    int exclude = 0 + solve(nums,queries,index+1);
    return max(include,exclude);
}


int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
    sort(queries.begin(), queries.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    });
    int sum = 0;
    for (int i = 0; i < queries.size(); ++i) {
        int index = queries[i][0];
        int value = queries[i][1];
        int save = nums[index];
        nums[index] = value;
        sum += solve(nums,queries,0);
        nums[index] = save;
    }
    return sum;
}

int main(){
    vector<int> nums = {0,3,3,3,1,-2};
    vector<vector<int>> queries = {{4,0},
                                   {1,0}};
    cout<<maximumSumSubsequence(nums,queries);

}