#include "iostream"
#include "vector"
#define MOD 100000007
using namespace std;

int mul(int a,int b){
    return (a%MOD * 1LL * b%MOD)%MOD;
}

int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}

int numberOfWays(int n, int k) {
    int secPrev = k;
    int firstPrev = add(k , mul(k,(k-1)));

    for (int i = 3; i <= n; ++i) {
        int curr = mul((k-1), add(firstPrev, secPrev) );
        secPrev = firstPrev;
        firstPrev = curr;
    }

    return firstPrev;
}

int main(){
    cout<<numberOfWays(234, 532);
}