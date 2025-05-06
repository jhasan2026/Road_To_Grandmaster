#include "iostream"

using namespace std;

double celsiusToFahrenheit(double cel){
    return (cel/5)*9 + 32;
}

int main(){
    cout<<celsiusToFahrenheit(32);
}