#include "iostream"

using namespace std;
int main()
{
    int fir=1,sec=1;
    int n;
    cin>>n;
    cout<<fir<<" "<<sec<<" ";
    for (int i = 1; i <=n-2; ++i) {
        int third=fir+sec;
        fir=sec;
        sec=third;
        cout<<third<<" ";
    }

}