#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int sum_of_digit(int n){
    int sum = 0;
    while (n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    cout<<sum_of_digit(7586);
}