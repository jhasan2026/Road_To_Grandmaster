#include "iostream"

using namespace std;

void printFibonacciSeries(int n){
    int first = 0,second = 1;
    cout<<first<<" "<<second<<" ";
    for (int i = 1; (first + second) <= n; ++i) {
        int third = first + second;
        first = second;
        second = third;
        cout<<third<<" ";
    }
}

int main(){
    printFibonacciSeries(500);
}