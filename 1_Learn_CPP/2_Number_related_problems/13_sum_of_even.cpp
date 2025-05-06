#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int sum_of_even(int n){
    return (n*(n+2))/4;
}

int bruteForce(int n){
    int sum=0;
    for (int i = 1; i <= n; ++i) {
        if(i%2==0){
            sum += i;
        }
    }
    return sum;
}

int main(){
    cout<<sum_of_even(100)<<endl;
    cout<<bruteForce(100)<<endl;

}