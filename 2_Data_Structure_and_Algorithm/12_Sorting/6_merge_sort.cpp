#include "iostream"

using namespace std;

void merge(int *arr,int start,int mid,int end){
    int s1 = mid+1-start;
    int s2 = end - mid;
    int sub1[s1] , sub2[s2];
    for (int i = 0; i < s1; ++i) {
        sub1[i] = arr[start + i];
    }
    for (int i = 0; i < s2; ++i) {
        sub2[i] = arr[(mid+1)+i];
    }
    int i=0 , j=0 , k=start;
    while (i<s1 && j<s2){
        if(sub1[i] < sub2[j]){
            arr[k] = sub1[i];
            k++;i++;
        }
        else {
            arr[k] = sub2[j];
            k++;j++;
        }
    }
    while (i<s1){
        arr[k] = sub1[i];
        k++;i++;
    }
    while (j<s2){
        arr[k] = sub2[j];
        k++;j++;
    }
}

void mergeSort(int *arr,int start,int end){
    if(start >= end){
        return;
    }
    int mid = (start + end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main(){
    int n=6;
    int arr[6] = {45 ,96 ,86 ,78 ,6,89};
    mergeSort(arr,0,n-1);
    for (int x:arr) {
        cout<<x<<" ";
    }
}