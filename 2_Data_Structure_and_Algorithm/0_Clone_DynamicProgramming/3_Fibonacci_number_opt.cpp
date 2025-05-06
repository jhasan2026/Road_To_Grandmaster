#include "iostream"
#include "vector"
using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }

    int secondPrev = 0;
    int firstPrev = 1;
    for (int i = 2; i <= n; ++i) {
        int curr = firstPrev + secondPrev;
        secondPrev = firstPrev;
        firstPrev = curr;
    }
    return firstPrev;
}

int main(){
    cout<<fib(6);
}