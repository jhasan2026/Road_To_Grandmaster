#include "iostream"
#include "vector"
using namespace std;

int numTrees(int n) {
    vector<int> dp(n+1,0);

    dp[0] = 1;
    dp[1] = 1;

    for (int index = 2; index <= n; ++index) {
        int ans = 0;
        for (int i = 1; i <= index; ++i) {
            ans += (dp[i-1] * dp[index-i]);
        }
        dp[index] = ans;
    }
    return dp[n];
}

int main(){
    cout<<numTrees(3);
}