#include "iostream"

using namespace std;

void printOdd(int *arr,int i,int n){
    if(i==n){
        return;
    }
    if(arr[i]%2!=0){
        cout<<arr[i]<<" ";
    }
    printOdd(arr,i+1,n);
}

int main(){
    int arr[] = {5,7,8,99,6,3};
    printOdd(arr,0,6);
}