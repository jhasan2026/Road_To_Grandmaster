#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int>& nums,int index,int diff) {

    int ans = 0;
    for (int previousIndex = index-1; previousIndex >=0 ; --previousIndex) {
        if(nums[index] - nums[previousIndex] == diff){
            ans = max(ans, 1 + solve(nums,previousIndex,diff));
        }
    }
    return ans;
}


int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2){
        return n;
    }
    int ans = INT_MIN;
    for (int index = 0; index < n; ++index) {
        for (int j = index+1; j < n; ++j) {
            ans = max(ans, 2 + solve(nums,index,nums[j] - nums[index]));
        }
    }
    return ans;
}


int main(){
    vector<int> nums = {9,4,7,2,10};
    cout<<longestArithSeqLength(nums);
}