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

    int sum[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout<<"Sum:";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
}