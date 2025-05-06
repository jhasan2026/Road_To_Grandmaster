#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<"LSB is 1";
    }
    else {
        cout<<"LSB is 0";
    }

}