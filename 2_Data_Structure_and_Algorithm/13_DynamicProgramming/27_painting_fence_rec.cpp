#include "iostream"
#include "vector"
#define MOD 1000000007

using namespace std;

int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a,int b){
    return (a%MOD * b%MOD)%MOD;
}

int solve(int n, int k) {
    if(n == 1){             //one fence can be paint with k colors
        return k;
    }
    if(n == 2){                             //two fence can be paint with (k + k*(k-1)) = k^2 colors
        return add(k,mul(k,k-1));
    }
    return add(mul(k-1, solve(n-1,k)),mul(k-1, solve(n-2,k)));      //f(n) = (k-1) * { f(n-2) + f(n-1) }
                                        //f(n-2) -> solution by last two combination
                                        //f(n-1) -> solution by last three combination
}

int numberOfWays(int n, int k) {
    return solve(n,k);
}

int main(){
    cout<<numberOfWays(4,2);
}