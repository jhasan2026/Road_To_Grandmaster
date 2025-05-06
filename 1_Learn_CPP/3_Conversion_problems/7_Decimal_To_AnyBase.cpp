#include "iostream"

using namespace std;

int decimal_to_anyBase(int decimal,int base){
    int anyBase = 0, i = 1;
    while (decimal){
        anyBase += (decimal % base) * i;
        i *= 10;
        decimal /= base;
    }
    return anyBase;
}

int main(){
    cout<<decimal_to_anyBase(99,9);
}