#include "iostream"
#include "vector"
using namespace std;

// problem

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0; // No prices means no profit

    vector<int> next(n+1,0);
    vector<int> curr(n+1,0);

    for (int index = n - 1; index >= 0; --index) {
        for (int operationNo = 0; operationNo <= 2 * k; ++operationNo) {
            int profit = 0;
            if (operationNo % 2 == 0) { // Buy mode
                int include = -prices[index] + next[operationNo + 1]; // if buy
                int exclude = 0 + next[operationNo]; // if not buy
                profit = max(include, exclude);
            } else { // Sell mode
                int include = prices[index] + next[operationNo + 1]; // if sell
                int exclude = 0 + next[operationNo]; // if not sell
                profit = max(include, exclude);
            }
            curr[operationNo] = profit;
        }
        next = curr;
    }

    return next[0];
}


int main(){
    vector<int> prices = {3,2,6,5,0,3};
    cout<<maxProfit(2,prices);
}