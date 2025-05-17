#include "iostream"
#include "vector"
using namespace std;

bool increasingTriplet(vector<int>& nums) {
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
    int ans = subsequence.size();
    if(ans >= 3){
        return true;
    }
    return false;
}




int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<increasingTriplet(nums);
}


