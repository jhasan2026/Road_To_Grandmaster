#include "iostream"

using namespace std;

bool checkPrimeNumber(int n){
    for (int i = 2; i <= n/2 ; ++i) {
        if(n%2==0){
            return false;
        }
    }
    return true;
}

int main(){
    cout<<checkPrimeNumber(41)<<endl;
}