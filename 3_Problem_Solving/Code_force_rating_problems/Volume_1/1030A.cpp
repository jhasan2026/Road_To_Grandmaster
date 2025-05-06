#include "iostream"
#include "vector"

using namespace std;

string solve(int n,int *arr){
    int sum=0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if(sum>=1){
            return "HARD";
        }
    }
    return "EASY";
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