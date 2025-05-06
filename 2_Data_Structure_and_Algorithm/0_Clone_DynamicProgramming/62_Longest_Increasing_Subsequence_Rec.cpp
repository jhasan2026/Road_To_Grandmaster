#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums,int currIndex,int prevIndex) {
    if(currIndex >= nums.size()){
        return 0;
    }
    int include = 0;
    if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
        include = 1 + solve(nums,currIndex+1,currIndex);
    }
    int exclude = 0 + solve(nums,currIndex+1,prevIndex);
    return max(include,exclude);
}

int lengthOfLIS(vector<int>& nums) {
    return solve(nums,0,-1);
}


int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums);
}