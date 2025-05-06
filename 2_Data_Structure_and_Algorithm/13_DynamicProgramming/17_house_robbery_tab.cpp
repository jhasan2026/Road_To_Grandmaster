#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int>& nums,int start,int end){
    vector<int> dp(end+2,0);
    dp[start] = nums[start];                            //startTh ans is numOfStart
    dp[start + 1] = max(nums[start],nums[start + 1]);   //(startTh + 1) ans is max of {numOfStart and (numOfStart + 1)}

    for (int i = start+2; i <= end; ++i) {
        int include = nums[i] + dp[i-2];        //if take the number skip index+1 and jump to the index+2
        int exclude = 0 + dp[i-1];              //if not take index+1 th number
        dp[i] = max(include,exclude);
    }
    return dp[end];
}

int rob(vector<int>& nums) {
    int n=nums.size();

    if(n == 1){
        return nums[0];
    }
    if(n==2){
        return max(nums[0],nums[1]);
    }


    int firstToSecLast = solve(nums,0,n-1);     //from 0th to nth houses
    int secToLast = solve(nums,1,n-2);          //from 1st to n-1 th houses
    return max(firstToSecLast,secToLast);
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    cout<<rob(nums);
}