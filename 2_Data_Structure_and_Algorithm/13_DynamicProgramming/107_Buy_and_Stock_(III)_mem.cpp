#include "iostream"
#include "vector"
using namespace std;


int solve(vector<int>& prices,int index,int buyMode,int limit,vector<vector<vector<int>>> &dp) {

    if(index>=prices.size()){
        return 0;
    }

    if(limit == 0){     //you can't sell more than 2 product
        return 0;
    }

    if(dp[index][buyMode][limit] != -1){
        return dp[index][buyMode][limit];
    }

    int profit = 0;
    if(buyMode){
        int include = -prices[index] + solve(prices,index+1,0,limit,dp);       //time for buy: if buy :: money lost
        int exclude = 0 + solve(prices,index+1,1,limit,dp);                        //not buy
        profit = max(include,exclude);
    }
    else{
        int include = prices[index] + solve(prices,index+1,1,limit-1,dp);      //time for sell: if sell :: get money (if sell limit--)
        int exclude = 0 + solve(prices,index+1,0,limit,dp);                                //not sell
        profit = max(include,exclude);
    }
    return dp[index][buyMode][limit] = profit;
}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(prices,0,1,2,dp);
}

int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(prices);
}