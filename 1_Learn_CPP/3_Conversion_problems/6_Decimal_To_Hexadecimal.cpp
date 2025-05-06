#include "iostream"

using namespace std;


char hexChar(int n){
    if(n>=0 && n<=9){
        return (char)n;
    }
    return (char)(n+55);
}

string decimal_to_octal(int decimal){
    string hexadecimal = "";
    int i = 1;
    while (decimal){
        hexadecimal += hexChar(((decimal % 16)*i)%16);
        i *= 10;
        decimal /= 16;
    }
    return hexadecimal;
}

int main(){
    cout<<decimal_to_octal(42);
}