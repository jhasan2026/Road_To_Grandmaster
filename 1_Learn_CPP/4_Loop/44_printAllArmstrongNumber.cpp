#include "iostream"
#include "cmath"

using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <=n ; ++i) {
        int n=i,dig=log10(i)+1;
        int sum=0;
        while (n!=0)
        {
            int rem=n%10;
            n/=10;
            int s=1;
            for (int j = 1; j <= dig; ++j) {
                s*=rem;
            }
            sum+=s;
        }
        if(sum==i)
        {
            cout<<i<<" ";
        }

    }


}
