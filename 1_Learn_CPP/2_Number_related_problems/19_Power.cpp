#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

long power(int x,int y){
    long sum = 1;
    for (int i = 1; i <= y; ++i) {
        sum *= x;
    }
    return sum;
}

int main(){
    cout<<power(5,3);
}