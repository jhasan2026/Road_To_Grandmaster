#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int swap_first_last_digit(int n){
    int last = n%10;
    int digit = log10(n);
    int first = (int)(n / pow(10,digit));
    n -= last;
    n += first;
    n = n%(int)pow(10,digit);
    n += pow(10,digit)*last;
    return n;
}

int main(){
    cout<<swap_first_last_digit(748569);
}