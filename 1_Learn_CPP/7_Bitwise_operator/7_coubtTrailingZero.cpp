#include "iostream"
#define SIZE sizeof(int)*8

using namespace std;
int main()
{
    int n,count=0;
    cin>>n;
    for (int i = 0; i < SIZE; ++i) {
        int bit=n>>i;
        if(bit&1)
        {
            break;
        }
        count++;
    }
    cout<<"Trailing zero is "<<count;


}