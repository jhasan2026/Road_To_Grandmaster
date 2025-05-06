#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int> &arr,int n){
    if(n==1){
        return 1;
    }
    int start = 0;
    int maxi = 0;
    int len = 1;
    for (int end = 1; end < n; ++end) {
        if(arr[end-1] <= arr[end] ){     //war
            len = end - start + 1;
        }
        else{
            start = end;
        }
        maxi = max(maxi, len);
    }
    return maxi;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<solve(arr,n);
}