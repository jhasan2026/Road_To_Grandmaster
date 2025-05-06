#include "iostream"
#include "vector"

using namespace std;

bool solve(vector<int>& nums,int target,int index) {
    if(index >= nums.size()){
        return false;
    }
    if(target < 0){
        return false;
    }
    if(target == 0){
        return true;
    }
    int include = solve(nums,target - nums[index],index+1);
    int exclude = solve(nums,target,index+1);
    return include || exclude;
}

bool canPartition(vector<int>& nums) {
    int sum=0;
    for (auto x:nums) {
        sum += x;
    }
    if(sum & 1){
        return false;
    }
    int target = sum/2;
    return solve(nums,target,0);
}

int main(){
    vector<int> nums = {1, 5, 11, 5};
    cout<<canPartition(nums);
}