#include "iostream"

using namespace std;

int decimal_to_octal(int decimal){
    int octal = 0, i = 1;
    while (decimal){
        octal += (decimal % 8) * i;
        i *= 10;
        decimal /= 8;
    }
    return octal;
}

int main(){
    cout<<decimal_to_octal(77);
}