#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool cmd(pair<int,int> p1,pair<int,int> p2){
    return p1.second <= p2.second;
}

void solve(int n,int *gifts){
    vector<pair<int,int>> list;
    for (int i = 0; i < n; ++i) {
        list.push_back({i+1,gifts[i]});
    }
    sort(list.begin(), list.end(), cmd);
    for(auto x:list){
        cout<<x.first<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    solve(n,arr);
}

