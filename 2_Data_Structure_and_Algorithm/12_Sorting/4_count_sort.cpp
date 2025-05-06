#include "iostream"
#define MOD 107

using namespace std;

void countSort(int *arr,int n){
   int freq[MOD] = {0};
    for (int i = 0; i < n; ++i) {
        (freq[arr[i]%MOD])++;
    }
    for (int i = 1; i < MOD; ++i) {
        freq[i]+=freq[i-1];
    }
    int output[n];
    for (int i = n-1; i >= 0; --i) {
        output[--freq[arr[i]%MOD]] = arr[i];
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

int main(){
    int n=6;
    int arr[6] = {45 ,96 ,86 ,78 ,6,89};
    countSort(arr,n);
    for (int x:arr) {
        cout<<x<<" ";
    }
}