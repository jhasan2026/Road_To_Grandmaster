#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <=n ; ++i) {
        int num=0;
        int p=i;
        while (p!=0)
        {
            int rem=p%10;
            p/=10;
            num=10*num+rem;
        }
        cout<<num<<" ";

    }

}