#include "iostream"

using namespace std;

void bubbleSort(int *arr,int n){
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-2; ++j) {
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int n=6;
    int arr[6] = {45 ,96 ,86 ,78 ,6,89};
    bubbleSort(arr,n);
    for (int x:arr) {
        cout<<x<<" ";
    }
}