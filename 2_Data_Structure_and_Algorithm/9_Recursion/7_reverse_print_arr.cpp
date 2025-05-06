#include "iostream"

using namespace std;

void reversePrint(int *arr,int i,int n){
    if(i==n){
        return;
    }
    reversePrint(arr,i+1,n);
    cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {5,7,8,9,6,3};
    reversePrint(arr,0,6);
}