#include "iostream"

using namespace std;
int main()
{
    int n;
    float sum=0;
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        sum+=(float )(i*i*i)/(i+1);
    }
    cout<<sum;

}