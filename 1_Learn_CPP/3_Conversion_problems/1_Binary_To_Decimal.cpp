#include "iostream"
#include "math.h"
using namespace std;

int binary_to_decimal(int binary_num){
    int decimal_num = 0,i=0;
    while (binary_num){
        decimal_num +=  (binary_num % 10) * pow(2,i);
        binary_num /= 10;
        i++;
    }
    return decimal_num;
}

int main(){
    cout<<binary_to_decimal(1010);
}