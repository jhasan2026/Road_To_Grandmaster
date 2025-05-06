#include "iostream"
#include "vector"

using namespace std;

int solve(vector<pair<int,int>> arr,int n){
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j){
                continue;
            }
            if(arr[i].first == arr[j].second){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i].first;
        cin>>arr[i].second;
    }
    cout<<solve(arr,n);
}

