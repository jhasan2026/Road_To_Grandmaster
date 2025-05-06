#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

void snake(int n,int m){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(i%2==1){
                cout<<"#";
            }
            else{
                if(j==1 && i%4==0){
                    cout<<"#";
                }
                else if(j==m && i%4==2){
                    cout<<"#";
                }
                else{
                    cout<<".";
                }
            }
        }
        cout<<endl;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    snake(n,m);
}