#include "iostream"

using namespace std;

int sumOfDigit(int n){
    int sum = 0;
    while (n){
        sum += n%10;
        n/=10;
    }
    return sum;
}

int main(){
    cout<<sumOfDigit(4562)<<endl;
}