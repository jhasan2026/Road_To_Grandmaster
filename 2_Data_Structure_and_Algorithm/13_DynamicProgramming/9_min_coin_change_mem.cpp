#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& coins, int amount,vector<int> &dp) {
    if(amount < 0){
        return INT_MAX;
    }
    if(amount == 0){
        return 0;
    }

    if(dp[amount] != -1){
        return dp[amount];
    }

    int numOfCoin = INT_MAX;
    for (auto coin:coins) {
        int temp = solve(coins,amount-coin,dp);

        if(temp != INT_MAX) {
            numOfCoin = min(numOfCoin,1 + temp);
        }
    }
    return dp[amount] = numOfCoin;
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,-1);
    int ans = solve(coins,amount,dp);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}


int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout<<coinChange(coins,amount);
}