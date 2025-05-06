#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

void multiplicationTable(int n){
    for (int i = 1; i <= 10; ++i) {
        cout<<i<<"*"<<n<<"="<<i*n<<endl;
    }
}

int main(){
    multiplicationTable(9);
}