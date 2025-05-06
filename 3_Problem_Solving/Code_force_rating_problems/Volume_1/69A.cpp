#include "iostream"
#include "vector"

using namespace std;

string solve(int n,int arr[][3]){
    int x=0,y=0,z=0;
    for (int i = 0; i < n; ++i) {
        x += arr[i][0];
        y += arr[i][1];
        z += arr[i][2];
    }
    if(x==0 && y==0 && z==0){
        return "YES";
    }
    return "NO";
}

int main(){
    int n;
    cin>>n;
    int arr[n][3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>arr[i][j];
        }
    }
    cout<<solve(n,arr);

}