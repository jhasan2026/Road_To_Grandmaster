#include "iostream"

using namespace std;
int main()
{
    int n,check=0;
    cin>>n;
    int mat1[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>mat1[i][j];
            if(i>j && mat1[i][j]!=0)
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
    if(check==0){
         cout<<"UpperTriangular Matrix";
    }else{
        cout<<"Not uppertriangular matrix";
    }

}