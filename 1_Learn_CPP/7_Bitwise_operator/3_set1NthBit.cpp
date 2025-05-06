#include "iostream"

using namespace std;
int main()
{
    int n,pos;
    cin>>n>>pos;
    int bit=1<<pos;
    int num=(n|bit);
    cout<<num;


}