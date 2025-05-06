#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    float sum=0;
    for (int i = 1; i <=n ; ++i) {
        int fact=1;
        for (int j = 1; j <=i; ++j) {
            fact*=j;
        }
        sum+=(float)i/fact;
    }
    cout<<sum;

}