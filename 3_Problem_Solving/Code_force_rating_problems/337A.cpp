#include "iostream"
#include "vector"
#include "math.h"
#include "algorithm"
using namespace std;

int solve(int noOfStudent,int n,vector<int> arr){
    int mini = INT_MAX;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n-noOfStudent+1; ++i) {
        int diff = arr[noOfStudent+i-1] - arr[i];
        mini = min(mini, diff);
    }
    return mini;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(m);
    for (int i = 0; i < m; ++i) {
        cin>>arr[i];
    }
    cout<<solve(n,m,arr);
}