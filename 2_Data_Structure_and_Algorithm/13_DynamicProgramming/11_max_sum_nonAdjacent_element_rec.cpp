#include "iostream"
#include "vector"

using namespace std;



int solve(vector<int> &nums,int index){
    if(index >= nums.size()){                   //till last element
        return 0;
    }
    int include = nums[index] + solve(nums,index + 2);      //if take the number skip index+1 and jump to the index+2
    int exlucde = solve(nums,index+1);                  //if not take index+1 th number
    return max(include,exlucde);                        //get max among them
}

int maxSumNonAdjElement(vector<int> &nums){
    return solve(nums,0);               //starts from 0th index
}

int main(){
    vector<int> nums ={2, 1, 4, 9};
    cout<<maxSumNonAdjElement(nums);
}