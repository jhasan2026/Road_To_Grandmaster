#include "iostream"
#include "vector"
using namespace std;

int numSquares(int n) {
    vector<int> dp(n+1,0);
    for (int num = 1; num <=n ; ++num) {
        int minOfWay=num;
        for (int i = 1; i*i <=num ; ++i) {
            minOfWay = min(minOfWay,1 + dp[num - (i*i)])  ;
        }
        dp[num] = minOfWay;
    }
    return dp[n];
}

int main(){
    cout<<numSquares(12);
}