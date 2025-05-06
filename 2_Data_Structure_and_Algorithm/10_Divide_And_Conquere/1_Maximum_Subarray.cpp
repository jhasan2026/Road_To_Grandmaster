#include "iostream"
#include "vector"
using namespace std;

int findCrossingMaxSum(vector<int> &arr,int start,int mid,int end){
    int sum = 0;


    int leftMaxOfSum = INT_MAX;
    for (int i = mid; i >= start ; --i) {           //from mid to left most --> find max sum
        sum += arr[i];
        leftMaxOfSum = max(leftMaxOfSum, sum);
    }

    sum = 0;
    int rightMaxOfSum = INT_MAX;
    for (int i = mid+1; i <= end ; ++i) {         //from mid to right most --> find max sum
        sum += arr[i];
        rightMaxOfSum = max(rightMaxOfSum, sum);
    }
    return leftMaxOfSum + rightMaxOfSum;
}


int findMaximumSubarray(vector<int> &arr,int start,int end) {
    if (start == end) {
        return arr[start];
    }
    int mid = (start + end) / 2;
    int leftMaxSum = findMaximumSubarray(arr, start, mid);         //left side maximum subarray
    int rightMaxSum = findMaximumSubarray(arr, mid + 1, end);     // right side
    int crossingMaxSum = findCrossingMaxSum(arr, start, mid, end);    //crossing the middle
    return max(leftMaxSum, max(rightMaxSum, crossingMaxSum));

}
int main(){
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
    cout<<findMaximumSubarray(arr,0,arr.size()-1)<<endl;
}