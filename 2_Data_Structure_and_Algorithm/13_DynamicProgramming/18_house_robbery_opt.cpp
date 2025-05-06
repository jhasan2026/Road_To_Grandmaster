#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int>& nums,int start,int end){
    int secondPrev = nums[start];                       //startTh ans is numOfStart
    int firstPrev = max(nums[start],nums[start + 1]);   //(startTh + 1) ans is max of {numOfStart and (numOfStart + 1)}

    for (int i = start+2; i <= end; ++i) {
        int include = nums[i] + secondPrev;         //if take the number skip index+1 and jump to the index+2
        int exclude = 0 + firstPrev;                //if not take index+1 th number
        int curr = max(include,exclude);
        secondPrev = firstPrev;
        firstPrev = curr;
    }
    return firstPrev;
}

int rob(vector<int>& nums) {
    int n=nums.size();

    if(n == 1){                         //startTh ans is numOfStart
        return nums[0];
    }
    if(n==2){                           //(startTh + 1) ans is max of {numOfStart and (numOfStart + 1)}
        return max(nums[0],nums[1]);
    }


    int firstToSecLast = solve(nums,0,n-1);         //from 0th to nth houses
    int secToLast = solve(nums,1,n-2);          //from 1st to n-1 th houses
    return max(firstToSecLast,secToLast);
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    cout<<rob(nums);
}