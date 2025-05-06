#include "iostream"

using namespace std;

int countEven(int *arr,int i,int n){
    if(i==n){
        return 0;
    }
    if(arr[i]%2==0){
        return 1 + countEven(arr,i+1,n);
    }
    return 0 + countEven(arr,i+1,n);
}

int main(){
    int arr[] = {5,7,8,99,6,3};
    cout<<countEven(arr,0,6);
}