#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

int solve(vector<int>& nums,int index,int diff,unordered_map<int,int> dp[]) {
    if(index < 0){                   //index:: i....0->stop
        return 0;
    }

    if(dp[index].count(diff)){
        return dp[index][diff];
    }

    int ans=0;
    for (int prev = index-1; prev >=0 ; --prev) {          //prev:: (i-1)...0->stop
        if(nums[index] - nums[prev] == diff){                    //if we have solved one case
            ans = max(ans , 1 + solve(nums,prev,diff,dp));     //+1 we have solved one case and rest of the case is for recursion
        }
    }
    return dp[index][diff] = ans;
}
int longestArithSeqLength(vector<int>& nums) {
    int n=nums.size();
    if(n <= 2){               //1 element array have AP size 1 and 2 element have 2 size
        return n;
    }

    unordered_map<int,int> dp[n+1];
    int ans=0;
    for (int i = 0; i < n; ++i) {        //iterate every pair of i
        for (int j = i+1; j < n; ++j) {     // and j
            ans = max(ans,2 + solve(nums,i,nums[j]-nums[i],dp));   //+2 we have already included 2 element to find their difference
}                                                                           //index:: 0...n-1
    }
    return ans;
}

int main(){
    vector<int> nums = {20, 1, 15, 3, 10, 5, 8};
    cout<<longestArithSeqLength(nums);
}