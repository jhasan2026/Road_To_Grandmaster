#include "iostream"

using namespace std;

void swap(int *arr,int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr,int start,int end){
    int pivot = arr[end];
    int j = start-1;
    for (int i = start; i <= end ; ++i) {
        if(arr[i] < pivot){
            j++;
            swap(arr,i,j);
        }
    }
    swap(arr,end,j+1);
    return j+1;
}

void quickSort(int *arr,int start,int end){
    if(start>=end){
        return;
    }
    int pivot = partition(arr,start,end);
    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);
}

int main(){
    int n=6;
    int arr[6] = {45 ,96 ,86 ,78 ,6,89};
    quickSort(arr,0,n-1);
    for (int x:arr) {
        cout<<x<<" ";
    }
}