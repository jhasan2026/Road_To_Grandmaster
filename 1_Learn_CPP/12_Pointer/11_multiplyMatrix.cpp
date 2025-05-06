#include "iostream"


using namespace std;
int main(){
    int n,m,p;
    cin>>n>>m>>p;
    int mat1[n][m],mat2[m][p],mul[n][p];
    cout<<"mat1:"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>*(*(mat1+i)+j);
        }
    }
    cout<<"mat2:"<<endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            cin>>*(*(mat2+i)+j);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            int sum=0;
            for (int k = 0; k < m; ++k) {
                sum+=(*(*(mat1+i)+k))*(*(*(mat2+k)+j));
            }
            *(*(mul+i)+j)=sum;
        }
    }
    cout<<"mul:"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            cout<<*(*(mul+i)+j)<<" ";
        }
        cout<<endl;
    }





















}

