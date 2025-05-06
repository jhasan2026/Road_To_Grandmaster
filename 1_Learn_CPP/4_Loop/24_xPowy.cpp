#include "iostream"

using namespace std;
int main()
{
    int x,y,sum=1;
    cin>>x>>y;
    for (int i = 1; i <=y ; ++i) {
        sum*=x;
    }
    cout<<sum;

}