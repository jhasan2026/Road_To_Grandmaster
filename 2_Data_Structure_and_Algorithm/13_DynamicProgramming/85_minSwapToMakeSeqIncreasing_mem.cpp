#include "iostream"
#include "vector"
using namespace std;


int solve(vector<int>& nums1, vector<int>& nums2,int index,int swapped, vector<vector<int>> &dp) {
    if(index >= nums1.size()){
        return 0;
    }

    if(dp[index][swapped] != -1){
        return dp[index][swapped];
    }

    int prevValue1 = nums1[index-1];
    int prevValue2 = nums2[index-1];

    if(swapped){
        swap(prevValue1,prevValue2);
    }

   //No-swap
   int exclude= INT_MAX;
    if(prevValue1 < nums1[index] && prevValue2<nums2[index]){
        exclude = solve(nums1,nums2,index+1, 0,dp);
    }
   //swap
   int include= INT_MAX;
    if(prevValue1 < nums2[index] && prevValue2 < nums1[index]){
        include = 1 + solve(nums1,nums2,index+1, 1,dp);
    }
    return dp[index][swapped] = min(include,exclude);
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    int n=nums1.size();

    vector<vector<int>> dp(n+1,vector<int>(2,-1));

    int ans = solve(nums1,nums2,1, 0,dp);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

int main(){
    vector<int> nums1 = {0, 3, 5, 8, 9};
    vector<int> nums2 = {2, 1, 4, 6, 9};
    cout<<minSwap(nums1,nums2);
}
