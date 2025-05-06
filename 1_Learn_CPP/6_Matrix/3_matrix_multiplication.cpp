#include "iostream"

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int matrix1[n][m];
    cout<<"matrix1:"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>matrix1[i][j];
        }
    }
    cout<<"matrix2:"<<endl;
    int p,q;
    cin>>p>>q;
    if(m!=p){

    }
    else{
        int matrix2[p][q];
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < q; ++j) {
                cin>>matrix2[i][j];
            }
        }

        int mul[n][q];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < q; ++j) {
                int sum = 0;
                for (int k = 0; k < m; ++k) {
                    sum += matrix1[i][k]*matrix2[k][j];
                }
                mul[i][j] = sum;
            }
        }
        cout<<"Sum:";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < q; ++j) {
                cout<<mul[i][j]<<" ";
            }
            cout<<endl;
        }
    }

}