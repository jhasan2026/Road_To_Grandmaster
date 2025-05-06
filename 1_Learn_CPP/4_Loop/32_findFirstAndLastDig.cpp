#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    int last=n%10,fir=0;
    while (n!=0)
    {
        int rem=n%10;
        n/=10;
        if(n==0)
        {
            fir=rem;
        }
    }
    cout<<fir<<" "<<last;

}