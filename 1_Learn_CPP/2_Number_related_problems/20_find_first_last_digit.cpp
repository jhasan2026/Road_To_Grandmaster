#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int first_and_last_digit(int n){
    int digit = log10(n);
    cout<<(int)(n / pow(10, digit))<<endl;
    cout<<n%10;
}

int main(){
    cout<<first_and_last_digit(5);
}