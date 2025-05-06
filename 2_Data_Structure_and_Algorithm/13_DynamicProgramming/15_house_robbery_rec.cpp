#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int>& nums,int start,int end){
    if(start >= end){
        return 0;
    }
    int include = nums[start] + solve(nums,start+2,end);        //if take the number skip index+1 and jump to the index+2
    int exclude = 0 + solve(nums,start+1,end);              //if not take index+1 th number
    return max(include,exclude);
}

int rob(vector<int>& nums) {
    int n=nums.size();
    int firstToSecLast = solve(nums,0,n);           //from 0th to nth houses
    int secToLast = solve(nums,1,n-1);          //from 1st to n-1 th houses
    return max(firstToSecLast,secToLast);
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    cout<<rob(nums);
}