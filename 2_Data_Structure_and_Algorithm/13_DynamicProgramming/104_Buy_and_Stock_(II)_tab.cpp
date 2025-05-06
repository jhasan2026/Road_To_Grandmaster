#include "iostream"
#include "vector"
using namespace std;



int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));

    for (int index = n-1; index >=0 ; --index) {
        for (int buyTime = 0; buyTime <= 1; ++buyTime) {
            int profit = 0;
            if(buyTime){
                int include = -prices[index] + dp[index+1][0];           //time for buy: if buy :: money lost
                int exclude = 0 + dp[index+1][1];                                  //not buy
                profit = max(include,exclude);
            }
            else{
                int include = prices[index] + dp[index+1][1];           //time for sell: if sell :: get money
                int exclude = 0 + dp[index+1][0];                              //not sell
                profit = max(include,exclude);
            }
            dp[index][buyTime] = profit;
        }
    }

    return dp[0][1];
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout<<maxProfit(prices);
}