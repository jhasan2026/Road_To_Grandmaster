#include "iostream"

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i ; ++j) {
            if(i%2==0){
                cout<<1+(j*2);
            }
            else{
                cout<<2+(j*2);
            }
        }
        cout<<endl;
    }
}
