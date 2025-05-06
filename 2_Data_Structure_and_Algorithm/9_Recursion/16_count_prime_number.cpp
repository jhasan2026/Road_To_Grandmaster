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

int countPrimeNumber(int *arr,int i,int n){
    if(i==n){
        return 0;
    }
    if(isPrime(arr[i],2)){
        return 1 + countPrimeNumber(arr,i+1,n);
    }
    return 0 + countPrimeNumber(arr,i+1,n);
}


int main(){
    int arr[] = {5,7,8,99,6,3};
    cout<<countPrimeNumber(arr,0,6);

}