#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& nums,int start,int end){
    int secondPrev = nums[start];
    int firstPrev = max(nums[start],nums[start + 1]);

    for (int i = start+2; i <= end; ++i) {
        int include = nums[i] + secondPrev;
        int exclude = 0 + firstPrev;
        int curr = max(include,exclude);
        secondPrev = firstPrev;
        firstPrev = curr;
    }
    return firstPrev;
}

int rob(vector<int>& nums) {
    int n=nums.size();

    if(n == 1){
        return nums[0];
    }
    if(n==2){
        return max(nums[0],nums[1]);
    }


    int firstToSecLast = solve(nums,0,n-1);
    int secToLast = solve(nums,1,n-2);
    return max(firstToSecLast,secToLast);
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    cout<<rob(nums);
}

