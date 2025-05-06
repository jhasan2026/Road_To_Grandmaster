#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int factorial(int n){
    int sum = 1;
    for (int i = 1; i <= n; ++i) {
        sum *= i;
    }
    return sum;
}

bool isStrongNumber(int n){
    int sum = 0;
    int N = n;
    while (N){
        sum += factorial(N%10);
        N /= 10;
    }
    return sum == n;
}

int main(){
    cout<<isStrongNumber(145);
}