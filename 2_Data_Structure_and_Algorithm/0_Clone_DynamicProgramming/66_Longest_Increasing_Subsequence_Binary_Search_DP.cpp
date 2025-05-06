#include "iostream"
#include "vector"
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> subsequence;
    int n = nums.size();
    if(n==0){
        return 0;
    }
    subsequence.push_back(nums[0]);
    for (auto num:nums) {
        if(num > subsequence.back()){
            subsequence.push_back(num);
        }
        else{
            int justLastGreatEleIndex = lower_bound(subsequence.begin(), subsequence.end(),num) -subsequence.begin();
            subsequence[justLastGreatEleIndex] = num;
        }
    }
    return subsequence.size();
}


int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums);
}