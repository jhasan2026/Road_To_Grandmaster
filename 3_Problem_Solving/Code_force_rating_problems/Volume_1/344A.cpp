#include "iostream"
#include "vector"

using namespace std;

int solve(int n,string arr[]){
    int cnt = 1;
    for (int i = 0; i < n-1; ++i) {
        if(arr[i]=="10" && arr[i+1]=="01"){
            cnt++;
        }
        else if(arr[i]=="01" && arr[i+1]=="10"){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    string arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<solve(n,arr);
}

