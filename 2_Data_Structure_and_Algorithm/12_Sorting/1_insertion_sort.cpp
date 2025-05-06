#include "iostream"

using namespace std;

void insertionSort(int *arr,int n){
    for (int i = 0; i < n; ++i) {
        int curr = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>curr){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

int main(){
    int n=6;
    int arr[6] = {45 ,96 ,86 ,78 ,6,89};
    insertionSort(arr,n);
    for (int x:arr) {
        cout<<x<<" ";
    }
}