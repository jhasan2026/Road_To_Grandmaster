#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums, int target) {
    if(target < 0){
        return 0;
    }
    if(target == 0){
        return 1;
    }
    int totalNoOfWays = 0;
    for (auto num:nums) {
        totalNoOfWays += solve(nums,target-num);
    }
    return totalNoOfWays;
}
int combinationSum4(vector<int>& nums, int target) {
    return solve(nums,target);
}


int main(){
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout<<solve(nums,target);
}