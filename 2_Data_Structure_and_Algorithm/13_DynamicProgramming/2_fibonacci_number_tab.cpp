#include "iostream"
#include "vector"

using namespace std;


int fibonacciNumberTab(int n){
    vector<int> dp(n+1,0);
    //    Oth fib is 0 and 1st is 1
    dp[0] = 0;
    dp[1] = 1;

    //    f(x) = f(x-1) + f(x-2)
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }


    return dp[n];
}

int main(){
    cout<<fibonacciNumberTab(6);
}