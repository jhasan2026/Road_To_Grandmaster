#include "iostream"


using namespace std;
int main(){
    int a,b,*ptr1=&a,*ptr2=&b;
    cin>>a>>b;
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
    cout<<a<<" "<<b;
}

