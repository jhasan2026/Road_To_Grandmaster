#include "iostream"
#include "vector"
using namespace std;


int solve(vector<int>& prices,int index,bool buyTime,int fees) {
    if(index >= prices.size()){
        return 0;
    }

    int profit = 0;
    if(buyTime){
        int include = -prices[index] + solve(prices,index+1, false,fees);  //time for buy: if buy :: money lost
        int exclude = 0 + solve(prices,index+1, true,fees);                             //not buy
        profit = max(include,exclude);
    }
    else{
        int include = prices[index] - fees + solve(prices,index+1, true,fees);      //time for sell: if sell :: get money
        int exclude = 0 + solve(prices,index+1, false,fees);                            //not sell
        profit = max(include,exclude);
    }
    return profit;
}

int maxProfit(vector<int>& prices, int fee) {
    return solve(prices,0, true,fee);
}

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    cout<<maxProfit(prices,2);
}