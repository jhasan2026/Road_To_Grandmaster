#include "iostream"
#include "vector"
#define MOD 1007

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    vector<int> map(MOD,0) ;
    for (int i = 0; i < n; ++i) {
        map[arr[i]%MOD]++;
    }
    for (int i = 0; i < MOD; ++i) {
        if(map[i]!=0){
            cout<<i<<endl;
        }
    }

}