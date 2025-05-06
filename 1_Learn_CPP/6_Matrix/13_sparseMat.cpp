#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    int mat1[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>mat1[i][j];
        }
    }
    int zero=0,non=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(mat1[i][j]==0){
                zero++;
            }else{
                non++;
            }
        }
    }
    if(zero>non)
    {
        cout<<"Sparse Mat";
    }else{
        cout<<"not sparse mat";
    }
}