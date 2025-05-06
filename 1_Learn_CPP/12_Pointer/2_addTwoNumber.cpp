#include "iostream"


using namespace std;
int main(){
    int a,b,*ptr1=&a,*ptr2=&b;
    cin>>a>>b;
    int sum=*ptr1 + *ptr2;
    cout<<sum;

}

