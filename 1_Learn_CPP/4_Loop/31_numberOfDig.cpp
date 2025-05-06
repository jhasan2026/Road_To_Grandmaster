#include "iostream"

using namespace std;
int main()
{
    int n,dig=0;
    cin>>n;
    while (n!=0)
    {
        dig++;
        n/=10;
    }
    cout<<dig;

}