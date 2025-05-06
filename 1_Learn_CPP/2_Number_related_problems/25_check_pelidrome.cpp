#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int reverse_of_number(int n){
    int sum = 0;
    while (n){
        sum = sum*10 + n%10;
        n/=10;
    }
    return sum;
}


bool checkPalindrome(int n){
    return reverse_of_number(n) == n;
}

int main(){
    cout<<checkPalindrome(78987);
}