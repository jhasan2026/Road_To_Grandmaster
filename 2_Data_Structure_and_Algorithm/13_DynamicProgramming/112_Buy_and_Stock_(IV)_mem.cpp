#include "iostream"
#include "vector"
using namespace std;

int solve(int k,vector<int>& prices,int index,int operationNo,vector<vector<int>> &dp) {

    if(index >= prices.size()){
        return 0;
    }

    if(operationNo == 2*k){                 //operation will be double of buy or sell --> one for buy another for sell
        return 0;
    }

    if(dp[index][operationNo] != -1){
        return dp[index][operationNo];
    }


    int profit = 0;
    if(operationNo%2 == 0){                         //0 2 4 ---> for buy mode (%2==0)
        int include = -prices[index] + solve(k,prices,index+1,operationNo+1,dp);       //if buy :: operation++
        int exclude = 0 + solve(k,prices,index+1,operationNo,dp);
        profit = max(include,exclude);
    }
    else{                                          //1 3 5---> for sell mode (%2==1)
        int include = prices[index] + solve(k,prices,index+1,operationNo+1,dp);        //if sell :: operation++
        int exclude = 0 + solve(k,prices,index+1,operationNo,dp);
        profit = max(include,exclude);
    }
    return dp[index][operationNo] = profit;
}
int maxProfit(int k,vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2*k,-1));
    return solve(k,prices,0,0,dp);
}

int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(2,prices);
}