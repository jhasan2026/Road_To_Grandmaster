#include "iostream"

using namespace std;

bool isEven(int n){
    return n%2==0;
}

int main(){
    cout<<isEven(5)<<endl;
    cout<<isEven(6)<<endl;
}