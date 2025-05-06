#include "iostream"
#include "vector"
using namespace std;

//probelm

int maxProfit(int k,vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for (int index = n-1; index >=0 ; --index) {
        for (int operationNo = 0; operationNo <= 2*k ; ++operationNo) {
            int profit = 0;
            if(operationNo%2 == 0){                         //0 2 4 ---> for buy mode (%2==0)
                int include = -prices[index] + dp[index+1][operationNo+1];       //if buy :: operation++
                int exclude = 0 + dp[index+1][operationNo];
                profit = max(include,exclude);
            }
            else{                                          //1 3 5---> for sell mode (%2==1)
                int include = prices[index] + dp[index+1][operationNo+1];        //if sell :: operation++
                int exclude = 0 + dp[index+1][operationNo];
                profit = max(include,exclude);
            }
            dp[index][operationNo] = profit;
        }
    }

    return dp[0][0];
}

int main(){
    vector<int> prices = {3,2,6,5,0,3};
    cout<<maxProfit(2,prices);
}