#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int squareSum(int n){
    return (n*(n+1)*(2*n+1))/6;
}
int bruteForce(int n){
    int sum=0;
    for (int i = 1; i <= n; ++i) {
        sum += i*i;
    }
    return sum;
}


int main(){
    cout<<squareSum(20)<<endl;
    cout<<bruteForce(20);
}