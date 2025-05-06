#include "iostream"

using namespace std;

int countDigit(int n){
    if(n==0){
        return 0;
    }
    return n%10 + countDigit(n/10);
}

int main(){
    cout<<countDigit(7852);
}