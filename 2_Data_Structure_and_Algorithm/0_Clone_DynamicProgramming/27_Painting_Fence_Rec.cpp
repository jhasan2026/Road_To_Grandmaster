#include "iostream"
#include "vector"
#define MOD 100000007
using namespace std;

int mul(int a,int b){
    return (a%MOD * b%MOD)%MOD;
}

int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}


int solve(int n, int k) {
    if(n==1){
        return k;
    }
    if(n==2){
        return k + (k*(k-1));
    }
    return mul((k-1), add(solve(n-1,k), solve(n-2,k)) );
}
int numberOfWays(int n, int k) {
    return solve(n,k);
}

int main(){
    cout<<numberOfWays(2,4);
}