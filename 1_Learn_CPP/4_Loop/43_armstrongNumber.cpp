#include "iostream"
#include "cmath"

using namespace std;
int main()
{
    int n;
    cin>>n;
    int dig=log10(n)+1;
    int m=n,sum=0;
    while (m!=0)
    {
        int rem=m%10;
        m/=10;
        int s=1;
        for (int i = 1; i <= dig; ++i) {
            s*=rem;
        }
        sum+=s;
    }
    if(sum==n)
    {
        cout<<"Armstrong number";
    }
    else {
        cout<<"not Armstrong number";
    }


}
