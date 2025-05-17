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

bool increasingTriplet(vector<int>& nums) {
    int ans = solve(nums,0,-1);
    if(ans >= 3){
        return true;
    }
    return false;
}


int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<increasingTriplet(nums);
}