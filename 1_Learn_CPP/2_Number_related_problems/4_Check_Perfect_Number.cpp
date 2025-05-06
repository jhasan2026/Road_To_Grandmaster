#include "iostream"

using namespace std;

bool isPerfect(int n){
    int sumOfDivisor = 0;
    for (int i = 1; i < n; ++i) {
        if(n%i == 0){
            sumOfDivisor += i;
        }
    }
    if(sumOfDivisor == n){
        return true;
    }
    return false;
}

int main(){
    cout<<isPerfect(28);
}