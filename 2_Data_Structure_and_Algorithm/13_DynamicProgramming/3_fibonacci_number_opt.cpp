#include "iostream"

using namespace std;


int fibonacciNumberOpt(int n){
    //    Oth fib is 0 and 1st is 1
    int secondPrev = 0;
    int firstPrev = 1;

    //    f(x) = f(x-1) + f(x-2)
    for (int i = 2; i <= n; ++i) {
        int curr = firstPrev + secondPrev;
        secondPrev = firstPrev;
        firstPrev = curr;
    }

    return firstPrev;
}

int main(){
    cout<<fibonacciNumberOpt(6);
}