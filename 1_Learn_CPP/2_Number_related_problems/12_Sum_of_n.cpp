#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int sumOfN(int n){
    return (n*(n+1))/2;
}

int bruteForce(int n){
    int sum=0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main(){
    cout<<sumOfN(100)<<endl;
    cout<<bruteForce(100);
}