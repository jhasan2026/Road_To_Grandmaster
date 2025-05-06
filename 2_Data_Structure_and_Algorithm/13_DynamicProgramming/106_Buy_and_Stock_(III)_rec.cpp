#include "iostream"
#include "vector"
using namespace std;


int solve(vector<int>& prices,int index,int buyMode,int limit) {

    if(index>=prices.size()){
        return 0;
    }

    if(limit == 0){     //you can't sell more than 2 product
        return 0;
    }

    int profit = 0;
    if(buyMode){
        int include = -prices[index] + solve(prices,index+1,0,limit);       //time for buy: if buy :: money lost
        int exclude = 0 + solve(prices,index+1,1,limit);                        //not buy
        profit = max(include,exclude);
    }
    else{
        int include = prices[index] + solve(prices,index+1,1,limit-1);      //time for sell: if sell :: get money (if sell limit--)
        int exclude = 0 + solve(prices,index+1,0,limit);                                //not sell
        profit = max(include,exclude);
    }
    return profit;
}

int maxProfit(vector<int>& prices) {
    return solve(prices,0,1,2);
}

int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(prices);
}