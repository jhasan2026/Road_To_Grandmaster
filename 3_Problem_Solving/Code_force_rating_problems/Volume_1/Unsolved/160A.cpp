#include "iostream"
#include "algorithm"
#include "math.h"
#include "vector"

using namespace std;

int solve(int n,vector<int> arr){
    int sum =0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    sum = ceil((float) sum /2);
    sort(arr.begin(), arr.end(),greater<int>());
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        if(temp > sum){
            return i+1;
        }
        temp += arr[i];
    }
    return n;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<solve(n,arr);
}