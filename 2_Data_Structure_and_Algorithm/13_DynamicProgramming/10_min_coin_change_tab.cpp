#include "iostream"
#include "vector"

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,0);

    for (int amt = 1; amt <= amount; ++amt) {
        int minNoCoin = INT_MAX;
        for (auto co:coins) {
            int ans=INT_MAX;
            if(amt - co >=0){
                ans = dp[amt - co];         //get ans from every coin of the coinList
            }
            if(ans != INT_MAX){                     //if the solution is possible (not more than we need)
                minNoCoin = min(minNoCoin, 1 + ans);     //1 for that coin and rest of the ans
            }
        }
         dp[amt] = minNoCoin;
    }

    int ans =  dp[amount];
    if(ans == INT_MAX){             //if it is not possible to make that amount of money by these coins
        return -1;
    }
    return ans;
}
int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout<<coinChange(coins,amount);
}