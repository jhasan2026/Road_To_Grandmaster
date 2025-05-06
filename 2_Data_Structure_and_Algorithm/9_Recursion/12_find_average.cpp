#include "iostream"

using namespace std;

double findAvg(int *arr,int n){
    if(n==0){
        return 0;
    }
    return ( arr[n] + ( (n-1)*findAvg(arr,n-1) ) )/n;
}

int main(){
    int arr[] = {5,7,8,9,6,3};
    cout<<findAvg(arr,5);
}