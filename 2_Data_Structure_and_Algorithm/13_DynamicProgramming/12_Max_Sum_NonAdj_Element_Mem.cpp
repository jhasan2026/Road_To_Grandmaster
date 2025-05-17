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

bool cmp(vector<int> &v1,vector<int> &v2){
    if(v1[0] < v2[0]){
        return true;
    }
    return false;
}

int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
    sort(queries.begin(), queries.end(),cmp);
    int sum = 0;
    int n = nums.size(), m= queries.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for (int i = 0; i < queries.size(); ++i) {
        int save = nums[queries[i][0]];
        nums[queries[i][0]] = queries[i][1];
        sum += solve(nums,queries,0);
        nums[queries[i][0]] = save;
    }
    return sum;
}

int main(){
    vector<int> nums = {3,5,9};
    vector<vector<int>> queries = {{1,-2},
                                   {0,-3}};
    cout<<maximumSumSubsequence(nums,queries);

}