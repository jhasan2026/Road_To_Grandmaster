#include "iostream"
#include "vector"
using namespace std;



int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,INT_MAX);
    dp[0] = 0;

    for (int amt = 1; amt <= amount; ++amt) {
        int numOfCoin = INT_MAX;
        for (auto coin:coins) {
            if(amt - coin >= 0) {
                int temp = dp[amt - coin];

                if (temp != INT_MAX) {
                    numOfCoin = min(numOfCoin, 1 + temp);
                }
            }
        }
        dp[amt] = numOfCoin;
    }

    if(dp[amount] == INT_MAX){
        return -1;
    }
    return dp[amount];
}


int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout<<coinChange(coins,amount);
}