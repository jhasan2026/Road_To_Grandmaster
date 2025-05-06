#include "iostream"
#define SIZE sizeof(int)*8

using namespace std;
int main()
{
    int n,pos=-1;
    cin>>n;
    for (int i = 0; i < SIZE; ++i) {
        int bit=n>>i;
        if(bit&1)
        {
            pos=i;
        }
    }
    if(pos==-1){
        cout<<"There is not highest bit";
    }else{
        cout<<pos<<"th is the highest bit";
    }

}