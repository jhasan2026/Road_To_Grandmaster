#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <=n ; ++i) {
        int m=i;
        int sum=0;
        while (m!=0)
        {
            int rem=m%10;
            m/=10;
            int s=1;
            for (int j = 1; j <=rem ; ++j) {
                s*=j;
            }
            sum+=s;
        }
        if(sum==i)
        {
            cout<<i<<" ";
        }
    }

}
