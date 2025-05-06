#include "iostream"


using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n],*ptr=arr;
    for (int i = 0; i < n; ++i) {
        cin>>*(arr+i);
    }
    int srch,check=0;
    cin>>srch;
    for (int i = 0; i < n; ++i) {
        if(srch==*(ptr+i)){
            check=1;
            cout<<"Found at:"<<i;
            break;
        }
    }
    if(check==0)
    {
        cout<<"Not found";
    }

}

