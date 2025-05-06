#include "bits/stdc++.h"

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0,j=1; i < size,j<size; ++i,j++) {
        if(nums[i] != nums[j]){
            nums[i] = nums[j];
            i++;
            j++;
        }
    }
}