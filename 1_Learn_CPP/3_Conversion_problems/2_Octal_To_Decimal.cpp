#include "iostream"
#include "math.h"
using namespace std;

int octal_to_decimal(int octal_num){
    int decimal_num = 0,i=0;
    while (octal_num){
        decimal_num +=  (octal_num % 10) * pow(8,i);
        octal_num /= 10;
        i++;
    }
    return decimal_num;
}

int main(){
    cout<<octal_to_decimal(777);
}