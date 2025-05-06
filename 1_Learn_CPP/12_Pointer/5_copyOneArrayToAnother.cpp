#include "iostream"


using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n],copy[n];
    int *ptrAr=arr,*ptrCo=copy;
    for (int i = 0; i < n; ++i) {
        cin>>*(ptrAr+i);
    }
    for (int i = 0; i < n; ++i) {
        *(ptrCo+i)=*(ptrAr+i);
    }
    for (int i = 0; i < n; ++i) {
        cout<<*(ptrCo+i)<<" ";
    }

}

