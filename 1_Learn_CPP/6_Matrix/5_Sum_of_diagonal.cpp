#include "iostream"

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int matrix1[n][m],sum = 0;
    cout<<"matrix1:"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>matrix1[i][j];
            if(i==j){
                sum+=matrix1[i][j];
            }
        }
    }
    cout<<sum;



}