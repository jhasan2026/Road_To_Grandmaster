#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int> &nums,int index,vector<int> &dp){
    if(index >= nums.size()){               //till last element
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int include = nums[index] + solve(nums,index + 2,dp);       //if take the number skip index+1 and jump to the index+2
    int exclude = solve(nums,index+1,dp);                   //if not take index+1 th number
    return dp[index] =  max(include,exclude);                       //get max among them
}

int maxSumNonAdjElement(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n+1,-1);
    return solve(nums,0,dp);            //starts from 0th index
}

int main(){
    vector<int> nums ={2, 1, 4, 9};
    cout<<maxSumNonAdjElement(nums);
}