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
    vector<int> dp(n+1,-1);
    dp[1] = k;
    dp[2] = add(k , mul(k,(k-1)));

    for (int i = 3; i <= n; ++i) {
        dp[i] = mul((k-1), add(dp[i-1], dp[i-2]) );
    }

    return dp[n];
}

int main(){
    cout<<numberOfWays(234, 532);
}