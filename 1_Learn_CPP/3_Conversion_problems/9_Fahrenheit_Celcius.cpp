#include "iostream"

using namespace std;

double FahrenheitToCelsius(double fah){
    return ((fah-32)/9)*5;
}

int main(){
    cout<<FahrenheitToCelsius(100);
}