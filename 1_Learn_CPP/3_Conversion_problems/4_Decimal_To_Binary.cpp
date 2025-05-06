#include "iostream"

using namespace std;

int decimal_to_binary(int decimal){
    int binary = 0, i = 1;
    while (decimal){
        binary += (decimal % 2) * i;
        i *= 10;
        decimal /= 2;
    }
    return binary;
}

int main(){
    cout<<decimal_to_binary(7);
}