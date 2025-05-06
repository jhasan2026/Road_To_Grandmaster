#include "iostream"
#include "vector"

using namespace std;

int sumOfArray(vector<int> arr,int start,int end){
    if(start == end){
        return arr[start];
    }
    int mid = (start + end) /2;
    int leftSum = sumOfArray(arr,start,mid);
    int rightSum = sumOfArray(arr,mid+1,end);
    return leftSum + rightSum;
}

int main(){
    vector<int> arr={45,8,6,9,38,99,2,6};
    cout<<sumOfArray(arr,0,arr.size()-1)<<endl;
}