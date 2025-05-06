#include "iostream"
#include "vector"

using namespace std;

int maxSumNonAdjElement(vector<int> &nums){
    int n=nums.size();
    int secondPrev = nums[0];               //0th element is always himself
    int firstPrev = max(nums[0],nums[1]);       //1st ans is either 0th one or 1st one

    for (int index = 2; index <= n ; ++index) {
        int include = nums[index] + secondPrev;     //if take the number skip index+1 and jump to the index+2
        int exclude = firstPrev;                    //if not take index+1 th number
        int curr =  max(include,exclude);           //get max among them
        secondPrev = firstPrev;
        firstPrev = curr;
    }
    return secondPrev;
}

int main(){
    vector<int> nums ={2, 1, 4, 9};
    cout<<maxSumNonAdjElement(nums);
}