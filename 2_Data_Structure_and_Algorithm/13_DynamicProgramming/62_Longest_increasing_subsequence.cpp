#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums,int curr,int prev) {
    if(curr == nums.size()){
        return 0;
    }
    int include = 0;
    if(prev==-1 || nums[curr] > nums[prev]) {                      //if the number is first-one or the number is greater than previous one:: take it
       include = 1 + solve(nums, curr+1,curr);
    }
    int exclude = 0 + solve(nums,curr+1,prev);
    return max(include,exclude);
}
int lengthOfLIS(vector<int>& nums) {
    return solve(nums,0,-1);
}

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums);
}