#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<"ODD:";
    for (int i = 1; i < n; i+=2) {
        cout<<i<<" ";
    }
    cout<<"\nEVEN:";
    for (int i = 2; i < n; i+=2) {
        cout<<i<<" ";
    }

}