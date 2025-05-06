#include "iostream"

using namespace std;
int main()
{
    int n,sum=0;
    cin>>n;
    int m=n;
    while (m!=0)
    {
        int rem=m%10;
        m/=10;
        int s=1;
        for (int i = 1; i <=rem ; ++i) {
            s*=i;
        }
        sum+=s;
    }
    if(sum==n)
    {
        cout<<"Strong number";
    }else{
        cout<<"Not strong number";
    }

}
