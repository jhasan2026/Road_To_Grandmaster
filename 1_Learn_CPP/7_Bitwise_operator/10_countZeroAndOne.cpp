#include "iostream"
#define SIZE sizeof(int)*8

using namespace std;
int main()
{
    int n,zero=0,one=0;
    cin>>n;
    for (int i = 0; i < SIZE; ++i) {
        int bit=n>>i;
        if(bit&1)
        {
            one++;
        }else{
            zero++;
        }

    }
    cout<<zero<<" "<<one;

}