#include "iostream"

using namespace std;

int main(){
    int n;
    cin>>n;
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
           if(flag==0){
               cout<<"1";
               flag=1;
           }
           else{
               cout<<"0";
               flag=0;
           }
        }
        cout<<endl;
    }
}