#include "iostream"
#include "vector"

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum=0;
    for (auto x:nums) {
        sum += x;
    }
    if(sum & 1){
        return false;
    }
    int target = sum/2;
    int n = nums.size();


    vector<bool> next(target+1, false);
    vector<bool> curr(target+1, false);

    curr[0] = true;
    next[0] = true;

    for (int index = n-1; index >=0 ; --index) {
        for (int tar = 0; tar <= target; ++tar) {
            bool include = false;
            if(tar-nums[index] >= 0) {
                include = next[tar - nums[index]];
            }
            bool exclude = next[tar];
            curr[tar] = include or exclude;
        }
        next = curr;
    }
    return next[target];
}

int main(){
    vector<int> nums = {1, 2, 5};
    cout<<canPartition(nums);
}