#include "iostream"
#include "math.h"
using namespace std;

bool isAdamNumber(int n){
    int Nsquare = n*n;
    int reverseOfNsquare = 0;
    while (Nsquare){
        reverseOfNsquare = reverseOfNsquare * 10 + Nsquare%10;
        Nsquare /=10;
    }
    int rootOfRevNSq = sqrt(reverseOfNsquare);
    int reverseOfRoot = 0;
    while (rootOfRevNSq){
        reverseOfRoot = reverseOfRoot*10 + rootOfRevNSq%10;
        rootOfRevNSq /= 10;
    }
    return n == reverseOfRoot;

}

int main(){
    cout<<isAdamNumber(12)<<endl;
}