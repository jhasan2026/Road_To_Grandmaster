#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

void solve(int n,vector<string> arr){
    vector<pair<string,int>> database;
    database.push_back({arr[0],0});
    cout<<"OK"<<endl;
    for (int i = 1; i < n; ++i) {
        bool flag = true;
        for (int j = database.size()-1; j >=0 ; --j) {
            if(arr[i] == database[j].first){
                database.push_back({arr[i],database[j].second+1});
                cout<<arr[i]<<database[j].second+1<<endl;
                flag = false;
                break;
            }
        }
        if(flag){
            database.push_back({arr[i],0});
            cout<<"OK"<<endl;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    solve(n,arr);
}