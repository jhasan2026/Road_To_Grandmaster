#include "iostream"
#include "vector"
using namespace std;

void primeNumberInARange(int range){
    vector<int> isPrime(range+1,0);
    for (int i = 2; i <= range; ++i) {
        if(isPrime[i] == 0){
            for (int j = i*i; j <= range; j+=i) {
                isPrime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= range; ++i) {
        if(isPrime[i] == 0){
            cout<<i<<" ";
        }
    }
}



int main(){
    primeNumberInARange(100);
}