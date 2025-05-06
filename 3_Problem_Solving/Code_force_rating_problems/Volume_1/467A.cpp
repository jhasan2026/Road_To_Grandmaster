#include "iostream"
#include "vector"

using namespace std;

int solve(int n,int arr[][2]){
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if((arr[i][1] - arr[i][0]) >=2){
            cnt++;
        }
    }
    return cnt;
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