#include "iostream"


using namespace std;
int main(){
    int n;
    cin>>n;
    int arr1[n],arr2[n],*ptr1=arr1,*ptr2=arr2;
    for (int i = 0; i < n; ++i) {
        cin>>*(ptr1+i);
    }
    for (int i = 0; i < n; ++i) {
        cin>>*(ptr2+i);
    }
    for (int i = 0; i < n; ++i) {
        int temp=*(ptr1+i);
        *(ptr1+i)=*(ptr2+i);
        *(ptr2+i)=temp;
    }
    for (int i = 0; i < n; ++i) {
        cout<<*(ptr1+i)<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<*(ptr2+i)<<" ";
    }

}

