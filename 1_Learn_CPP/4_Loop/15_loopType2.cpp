#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i = 0,j=1; i < n; ++i,j+=2) {
        cout<<j<<" ";
    }

}