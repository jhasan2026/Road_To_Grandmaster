#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <=n ; ++i) {
        int check=0;
        for (int j = 2; j <= i/2; ++j) {
            if(i%j==0)
            {
                check=1;
                break;
            }
        }
        if(check==0)
        {
            cout<<i<<" ";
        }
    }
}
