#include "iostream"

using namespace std;

bool isPrime(int n,int i){
    if(i==n){
        return true;
    }
    if(n%i==0){
        return false;
    }
    return isPrime(n,i+1);

}

void printPrimeNumber(int *arr,int i,int n){
    if(i==n){
        return;
    }
    if(isPrime(arr[i],2)){
        cout<<arr[i]<<" ";
    }
    printPrimeNumber(arr,i+1,n);
}


int main(){
    int arr[] = {5,7,8,99,6,3};
    printPrimeNumber(arr,0,6);

}