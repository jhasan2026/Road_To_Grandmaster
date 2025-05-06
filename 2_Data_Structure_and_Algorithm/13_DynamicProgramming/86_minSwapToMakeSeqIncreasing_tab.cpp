#include "iostream"
#include "vector"
using namespace std;


int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    int n=nums1.size();

    vector<vector<int>> dp(n+1,vector<int>(2,0));

    for (int index = n-1; index >= 0 ; --index) {
        for (int swapped = 1; swapped >=0 ; --swapped) {
            int prevValue1 = nums1[index-1];
            int prevValue2 = nums2[index-1];

            if(swapped){
                swap(prevValue1,prevValue2);
            }

            //No-swap
            int exclude= INT_MAX;
            if(prevValue1 < nums1[index] && prevValue2<nums2[index]){
                exclude = dp[index+1][0];
            }
            //swap
            int include= INT_MAX;
            if(prevValue1 < nums2[index] && prevValue2 < nums1[index]){
                include = 1 + dp[index+1][1];
            }
            dp[index][swapped] = min(include,exclude);
        }
    }

    int ans = dp[1][0];
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

int main(){
    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};
    cout<<minSwap(nums1,nums2);
}
