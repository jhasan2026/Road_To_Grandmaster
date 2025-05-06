#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    int mat1[n][n],mat[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>mat1[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j]=mat1[j][i];
        }
    }
    int check=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(mat1[i][j]!=mat[i][j])
            {
                check=1;
                break;
            }
        }
        if(check==1)
        {
            break;
        }
    }
    if(check==0)
    {
        cout<<"Transpose Matrix";
    }
}