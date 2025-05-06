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
            break;
        }
    }
    if(pos==-1)
    {
        cout<<"There is not a lowest bit";
    }else{
        cout<<pos<<"th is the lowest bit";
    }

}