#include "iostream"
#include "vector"
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int>currVec (n+1,0);
    vector<int>nextVec (n+1,0);

    for (int currIndex = n-1; currIndex >=0 ; --currIndex) {
        for (int prevIndex = currIndex-1; prevIndex >=-1 ; --prevIndex) {
            int include = 0;
            if(prevIndex == -1 || nums[currIndex] > nums[prevIndex]){
                include = 1 + nextVec[currIndex+1];
            }
            int exclude = 0 + nextVec[prevIndex+1];
            currVec[prevIndex+1] = max(include,exclude);
        }
        nextVec = currVec;
    }
    return nextVec[0];
}


int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums);
}