#include "iostream"
#include "math.h"
using namespace std;

int nDigit(int n){
    if(n == 0){
        return 1;
    }
    return log10(n)+1;
}

bool isArmstrong(int n){
    int N = n;
    int digit = nDigit(n);
    int sum = 0;
    while (n){
        int rem = n % 10;
        sum += pow(rem,digit);
        n/=10;
    }
    return N == sum;
}

void printAllArstrongNumber(int range){
    for (int i = 1; i <= range; ++i) {
        if(isArmstrong(i)){
            cout<<i<<" ";
        }
    }
}

int main(){
    printAllArstrongNumber(500);
}