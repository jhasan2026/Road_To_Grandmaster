#include "iostream"
#include "vector"

using namespace std;

int solve(int n,int arr[][2]){
    int maxi = INT_MIN;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        curr -= arr[i][0];
        curr += arr[i][1];
        maxi = max(maxi,curr);
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int arr[n][2];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    cout<<solve(n,arr);
}