#include "iostream"

using namespace std;

int findMax(int *arr,int i,int n){
    if(i==n-1){
        return arr[i];
    }
    return max(arr[i],findMax(arr,i+1,n));
}

int main(){
    int arr[] = {5,7,8,99,6,3};
    cout<<findMax(arr,0,6);
}