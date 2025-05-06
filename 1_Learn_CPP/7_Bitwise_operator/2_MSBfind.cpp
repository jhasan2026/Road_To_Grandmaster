#include "iostream"
#define SIZE sizeof(int)*8

using namespace std;
int main()
{
    int n;
    cin>>n;
    int bit=1<<SIZE-1;
    if(n&bit)
    {
        cout<<"MSB is 1";
    }
    else{
        cout<<"MSB is 0";
    }


}