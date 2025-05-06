#include "iostream"

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(n-j <= n-i){
                cout<<n-i;
            }
            else{
                cout<<n-j;
            }
        }
        cout<<endl;
    }
}