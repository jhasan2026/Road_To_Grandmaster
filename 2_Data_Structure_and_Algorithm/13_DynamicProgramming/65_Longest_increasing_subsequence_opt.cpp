#include "iostream"
#include "vector"
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> currVec(n+1,0);
    vector<int> nextVec(n+1,0);
    for (int curr = n-1; curr >= 0; --curr) {
        for (int prev = curr-1; prev >= -1 ; --prev) {
            int include = 0;
            if(prev==-1 || nums[curr] > nums[prev]) {                      //if the number is first-one or the number is greater than previous one:: take it
                include = 1 + nextVec[curr+1];
            }
            int exclude = 0 + nextVec[prev+1];
            currVec[prev+1] = max(include,exclude);
        }
        nextVec = currVec;
    }
    return nextVec[0];
}

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums);
}