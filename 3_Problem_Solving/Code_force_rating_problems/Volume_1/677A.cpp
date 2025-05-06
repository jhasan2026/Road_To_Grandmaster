#include "iostream"
#include "vector"

using namespace std;

int solve(int n,int h,int *arr){
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(arr[i] > h){
            cnt++;
        }
    }
    return (cnt*2) + (n-cnt);
}

int main(){
    int n,h;
    cin>>n>>h;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<solve(n,h,arr);
}