#include "iostream"

using namespace std;

int main(){
    int n;
    cin>>n;
    int k=2*n+1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if(j<=k-1-i){
               if(j<=i){
                   cout<<n-j;
               }
               else{
                   cout<<n-i;
               }
            }
            else{
                if(j<=i){
                    cout<<i-n;
                }
                else{
                    cout<<j-n;
                }
            }
        }
        cout<<endl;
    }
}