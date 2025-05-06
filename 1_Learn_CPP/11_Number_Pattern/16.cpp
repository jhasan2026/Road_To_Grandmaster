#include "iostream"

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int x=i+1;
        for (int j = 0; j < n; ++j) {
            if(j+1+i>n){
                x--;
                cout<<x;
            }
            else{
                cout<<(j+1)+i;
            }
        }
        cout<<endl;
    }
}