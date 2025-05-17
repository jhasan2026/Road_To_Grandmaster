#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped) {

    if(index >= nums1.size()){
        return 0;
    }

    int previousValue1 = nums1[index-1];
    int previousValue2 = nums2[index-1];

    if(swapped){
        swap(previousValue1,previousValue2);
    }

    //  No Swap (first try)
    int exclude = INT_MAX;
    if(previousValue1 < nums1[index] && previousValue2 < nums2[index]){
        exclude = 0 + solve(nums1,nums2,index+1, false);
    }

    // Swapped
    int include = INT_MAX;
    if(previousValue1 < nums2[index] && previousValue2 < nums1[index]){
        include = 1 + solve(nums1,nums2,index+1, true);
    }
    return min(include, exclude);
}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    int ans = solve(nums1,nums2,1, false);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

int main(){
    vector<int> nums1 = {1,3,5,4};
    vector<int> nums2 = {1,2,3,7};
    cout<<minSwap(nums1,nums2);

}