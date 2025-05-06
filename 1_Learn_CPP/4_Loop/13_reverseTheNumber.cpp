#include "iostream"

using namespace std;
int main()
{
    int n,sum=0;
    cin>>n;
    while (n!=0)
    {
        int rem=n%10;
        n/=10;
        sum=sum*10+rem;
    }
    cout<<sum;

}