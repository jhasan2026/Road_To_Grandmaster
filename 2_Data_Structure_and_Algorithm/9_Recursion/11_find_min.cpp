#include "iostream"

using namespace std;

int findMin(int *arr,int i,int n){
    if(i==n-1){
        return arr[i];
    }
    return min(arr[i],findMin(arr,i+1,n));
}

int main(){
    int arr[] = {5,7,8,99,6,3};
    cout<<findMin(arr,0,6);
}