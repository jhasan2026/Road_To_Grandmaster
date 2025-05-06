#include "iostream"

using namespace std;

int findSum(int *arr,int i,int n){
    if(i==n){
        return 0;
    }
    return arr[i] + findSum(arr,i+1,n);
}

int main(){
    int arr[] = {5,7,8,9,6,3};
    cout<<findSum(arr,0,6);
}