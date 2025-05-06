#include "iostream"

using namespace std;
int main()
{
    int n,check=0;
    cin>>n;
    for (int i = 2; i <=n/2 ; ++i) {
        if(n%i==0)
        {
            check=1;
            break;
        }
    }
    if(check==0)
    {
        cout<<"Prime number";
    }
    else {
        cout<<"Not prime number";
    }

}