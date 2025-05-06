#include "iostream"

using namespace std;

long findProduct(int *arr,int i,int n){
    if(i==n){
        return 1;
    }
    return arr[i] * findProduct(arr,i+1,n);
}

int main(){
    int arr[] = {5,7,8,9,6,3};
    cout<<findProduct(arr,0,6);
}