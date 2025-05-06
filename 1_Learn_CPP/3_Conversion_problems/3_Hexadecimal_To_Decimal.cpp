#include "iostream"
#include "math.h"
using namespace std;

int hexaValue(char c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    }
    return (int)c - 55;
}

int hexadecimal_TO_decimal(string hexadecimal){
    int decimal = 0,j=0;
    for (int i = hexadecimal.size()-1; i >=0 ; --i) {
        decimal += hexaValue(hexadecimal[i]) * pow(16,j);
        j++;
    }
    return decimal;
}

int main(){
    cout<<hexadecimal_TO_decimal("3B2C");
}