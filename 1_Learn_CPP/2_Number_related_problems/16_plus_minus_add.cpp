#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int plus_minus_add(int n){
    int sum = n/2;
    if(n%2==1){
        sum -= n;
    }
    return sum;
}

int bruteForce(int n){
    int sum= 0 ;
    for (int i = 1; i <= n; ++i) {
        if(i%2 == 1){
            sum -= i;
        }
        else{
            sum += i;
        }
    }
    return sum;
}

int main(){
    cout<<plus_minus_add(11)<<endl;
    cout<<bruteForce(11);
}