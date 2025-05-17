#include "iostream"
#include "vector"
#include "math.h"
#include "algorithm"
using namespace std;

int solve(int n, int *arr){
    int sum = 0, count=0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if(sum < 0){
            count++;
        }
        sum = max(0,sum);
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<solve(n,arr);
}