#include "iostream"

using namespace std;

int reverse_of_number(int n){
    int sum = 0;
    while (n){
        sum = sum*10 + n%10;
        n/=10;
    }
    return sum;
}

int main(){
    cout<<reverse_of_number(78529)<<endl;
}