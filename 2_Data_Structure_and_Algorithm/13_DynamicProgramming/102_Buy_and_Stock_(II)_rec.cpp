#include "iostream"
#include "vector"
using namespace std;


int solve(vector<int>& prices,int index,bool buyTime) {
    if(index >= prices.size()){
        return 0;
    }

    int profit = 0;
    if(buyTime){
        int include = -prices[index] + solve(prices,index+1, false);  //time for buy: if buy :: money lost
        int exclude = 0 + solve(prices,index+1, true);                             //not buy
        profit = max(include,exclude);
    }
    else{
        int include = prices[index] + solve(prices,index+1, true);      //time for sell: if sell :: get money
        int exclude = 0 + solve(prices,index+1, false);                            //not sell
        profit = max(include,exclude);
    }
    return profit;
}

int maxProfit(vector<int>& prices) {
    return solve(prices,0, true);
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout<<maxProfit(prices);
}