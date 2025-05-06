#include "iostream"
#include "vector"
using namespace std;


int solve(vector<int>& prices,int index,int buyTime,vector<vector<int>> &dp) {
    if(index >= prices.size()){
        return 0;
    }

    if(dp[index][buyTime] != -1){
        return dp[index][buyTime];
    }

    int profit = 0;
    if(buyTime){
        int include = -prices[index] + solve(prices,index+1, 0,dp);     //time for buy: if buy :: money lost
        int exclude = 0 + solve(prices,index+1, 1,dp);                                  //not buy
        profit = max(include,exclude);
    }
    else{
        int include = prices[index] + solve(prices,index+1, 1,dp);           //time for sell: if sell :: get money
        int exclude = 0 + solve(prices,index+1, 0,dp);                              //not sell
        profit = max(include,exclude);
    }
    return dp[index][buyTime] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    return solve(prices,0, 1,dp);
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout<<maxProfit(prices);
}