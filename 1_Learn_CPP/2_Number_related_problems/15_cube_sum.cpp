#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int cube_sum(int n){
    return pow((n*(n+1)/2),2);
}

int bruteForce(int n){
    int sum=0;
    for (int i = 1; i <= n; ++i) {
        sum += i*i*i;
    }
    return sum;
}

int main(){
    cout<<cube_sum(20)<<endl;
    cout<<bruteForce(20);
}