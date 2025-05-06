#include "iostream"


using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n],*ptr=arr;
    for (int i = 0; i < n; ++i) {
        cin>>*(arr+i);
    }
    for (int i = 0; i <= n/2; ++i) {
        int temp=*(ptr+i);
        *(ptr+i)=*(ptr+n-1-i);
        *(ptr+n-1-i)=temp;
    }
    for (int i = 0; i < n; ++i) {
        cout<<*(ptr+i)<<" ";
    }

}

