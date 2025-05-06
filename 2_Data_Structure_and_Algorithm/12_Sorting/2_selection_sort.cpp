#include "iostream"

using namespace std;

void selectionSort(int *arr,int n){
    for (int i = 0; i < n; ++i) {
        int minVal = arr[i], minIdx = i;
        for (int j = i+1; j < n; ++j) {
            if(arr[j] < minVal){
                minVal = arr[j];
                minIdx = j;
            }
        }
        arr[minIdx] = arr[i];
        arr[i] = minVal;
    }
}

int main(){
    int n=6;
    int arr[6] = {45 ,96 ,86 ,78 ,6,89};
    selectionSort(arr,n);
    for (int x:arr) {
        cout<<x<<" ";
    }
}