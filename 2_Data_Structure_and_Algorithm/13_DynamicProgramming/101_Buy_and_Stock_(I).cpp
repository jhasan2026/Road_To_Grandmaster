#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& prices) {
    int miniPrice = prices[0];
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); ++i) {
        int diff = prices[i] - miniPrice;
        maxProfit = max(maxProfit, diff);
        miniPrice = min(miniPrice, prices[i]);
    }
    return maxProfit;
}
int maxProfit(vector<int>& prices) {
    return solve(prices);
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout<<maxProfit(prices);
}