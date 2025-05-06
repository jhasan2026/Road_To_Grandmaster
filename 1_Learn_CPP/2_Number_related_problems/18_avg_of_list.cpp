#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

double avg(int *arr,int n){
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return (double )sum/n;
}

int main(){
    int arr[8] = {4,5,6,9,2,3,4,8};
    cout<<avg(arr,8);
}