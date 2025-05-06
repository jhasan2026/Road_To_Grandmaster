#include "iostream"

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int matrix1[n][m],matrix2[n][m];
    cout<<"matrix1:"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>matrix1[i][j];
        }
    }
    cout<<"matrix2:"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>matrix2[i][j];
        }
    }

    int flag=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(matrix1[i][j] != matrix2[i][j]){
                cout<<"Matrix are not equal";
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag==0){
        cout<<"Two matrix are equal";
    }

}