#include "iostream"

using namespace std;
int main()
{
    int n,dig=0;
    cin>>n;
    int m=n,p=n;
    while (n!=0)
    {
        dig++;
        n/=10;
    }
    int arr[dig];
    int i=0;
    while (m!=0)
    {
        int rem=m%10;
        m/=10;
        arr[i]=rem;
        i++;
    }
    int temp=arr[0];
    arr[0]=arr[dig-1];
    arr[dig-1]=temp;

    int sum=0;
    for (int i = dig-1; i >=0; --i) {
        sum=sum*10+arr[i];
    }
    cout<<sum;

}