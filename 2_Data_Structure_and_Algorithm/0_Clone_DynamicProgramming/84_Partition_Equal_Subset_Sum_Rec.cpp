#include "iostream"
#include "vector"
using namespace std;

bool solve(vector<int>& nums,int index,int target) {
    if(index >= nums.size()){
        return false;
    }
    if(target < 0){
        return false;
    }
    if(target == 0){
        return true;
    }
    int include = solve(nums,index+1,target-nums[index]);
    int exclude = solve(nums,index+1,target);
    return include || exclude;
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto num:nums) {
        sum += num;
    }
    if(sum%2 == 1){
        return false;
    }
    return solve(nums,0,sum/2);

}


int main(){
    vector<int> nums = {1, 5, 11, 5};
    cout<<canPartition(nums);
}