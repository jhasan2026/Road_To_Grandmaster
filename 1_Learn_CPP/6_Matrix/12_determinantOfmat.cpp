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
    int check=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if((i==j && mat1[i][j]!=1) || (i!=j && mat1[i][j]!=0)){
                check=1;
                break;
            }
        }
        if(check==1){
            break;
        }
    }
    if(check==0){
        cout<<"Identity matrix";
    }else{
        cout<<"Not identity mat";
    }
}