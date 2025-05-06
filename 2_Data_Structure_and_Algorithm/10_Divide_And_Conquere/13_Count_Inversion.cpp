#include "iostream"
#include "vector"

using namespace std;

int mergeCounter(vector<int> &arr,int start,int mid,int end){
    int size1 = mid+1 - start;
    int size2 = end - mid;
    int sub1[size1];
    int sub2[size2];

    for (int i = 0; i < size1; ++i) {
        sub1[i] = arr[start + i];
    }
    for (int i = 0; i < size2; ++i) {
        sub2[i] = arr[mid+1 + i];
    }

    int count = 0;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if(sub1[i] > sub2[j]){
                count++;
            }
        }
    }
    return count;
}

void countInversion(vector<int> &arr,int start,int end,int &inversionCount){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    countInversion(arr,start,mid,inversionCount);
    countInversion(arr,mid+1,end,inversionCount);
    inversionCount += mergeCounter(arr,start,mid,end);
}

int main(){
    vector<int> arr={45,8,6,9,38,99,2,6};
    int inversion=0;
    countInversion(arr,0,arr.size()-1,inversion);
    cout<<inversion<<endl;
}