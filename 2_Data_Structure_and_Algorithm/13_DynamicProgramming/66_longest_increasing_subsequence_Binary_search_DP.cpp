#include "iostream"
#include "vector"
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n= nums.size();
    if(n==0){
        return 0;
    }

    vector<int> subSequence;
    subSequence.push_back(nums[0]);
    for (int i = 1; i < n; ++i) {
        if(nums[i] > subSequence.back()){
            subSequence.push_back(nums[i]);
        }
        else{
            int justGreaterElement = lower_bound(subSequence.begin(), subSequence.end(),nums[i]) - subSequence.begin();
            subSequence[justGreaterElement] = nums[i];
        }
    }
    return subSequence.size();
}

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums);
}