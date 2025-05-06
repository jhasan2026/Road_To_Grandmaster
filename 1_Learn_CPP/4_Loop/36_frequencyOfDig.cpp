#include "iostream"
#include "cmath"

using namespace std;
int main()
{
    int n;
    cin>>n;
    int dig=log10(n)+1;
    int arr[dig],uni[dig],j=0;
    while (n!=0)
    {
        int rem=n%10;
        arr[j]=rem;
        uni[j]=-1;
        j++;
        n/=10;
    }
    for (int i = 0; i < dig; ++i) {
        int count=1;
        for (int k = i+1; k < dig; ++k) {
            if(arr[i]==arr[k])
            {
                count++;
                uni[k]=0;
            }
        }
        if(uni[i]!=0)
        {
            uni[i]=count;
        }
    }
    for (int i = 0; i < dig; ++i) {
        if(uni[i]!=0)
        {
            cout<<arr[i]<<"is in the number times "<<uni[i]<<endl;
        }
    }
}
