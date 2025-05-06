#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int generalSumFormula(int first,int distance,int n){
    return ((2*first + (n-1)*distance)*n)/2;
}

int plus_minus_sq(int n){
    //-1^2 + 2^2 - 3^2 + .....
    //3+7+11+15+…
    return generalSumFormula(3,4,n/2);
}

int bruteForce(int n){
    int sum= 0 ;
    for (int i = 1; i <= n; ++i) {
        if(i%2 == 1){
            sum -= i*i;
        }
        else{
            sum += i*i;
        }
    }
    return sum;
}

int main(){
    cout<<plus_minus_sq(50)<<endl;
    cout<<bruteForce(50);
}