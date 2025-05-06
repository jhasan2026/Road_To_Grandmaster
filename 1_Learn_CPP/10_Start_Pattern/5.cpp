

#include "iostream"

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2*n-1; ++j) {
            if(j>=n-1-i and j<(2*n)-1-i and (i==0 or i==n-1 or j==n-1-i or j==(2*n)-2-i)){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}

