#include "iostream"

using namespace std;

void printArray(int *arr,int i,int n){
    if(i==n){
        return;
    }
    cout<<arr[i]<<" ";
    printArray(arr,i+1,n);
}

int main(){
    int arr[] = {5,7,8,9,6,3};
    printArray(arr,0,6);
}