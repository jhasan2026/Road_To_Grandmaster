#include "iostream"
#include "vector"

using namespace std;

int maxSumNonAdjElement(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n+1,0);
    dp[0] = nums[0];                        //0th element is always himself
    dp[1] = max(nums[0],nums[1]);           //1st ans is either 0th one or 1st one

    for (int index = 2; index <= n ; ++index) {
        int include = nums[index] + dp[index-2];        //if take the number skip index+1 and jump to the index+2
        int exclude = dp[index-1];                  //if not take index+1 th number
        dp[index] =  max(include,exclude);          //get max among them
    }
    return dp[n-1];
}

int main(){
    vector<int> nums ={2, 1, 4, 9};
    cout<<maxSumNonAdjElement(nums);
}