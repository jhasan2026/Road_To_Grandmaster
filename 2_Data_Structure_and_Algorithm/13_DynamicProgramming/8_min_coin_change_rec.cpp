#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int>& coins, int amount){
    if(amount < 0){                         //if we take more than we needed
        return INT_MAX;                     //make a ignore by infinity by min func
    }
    if(amount == 0){     //if the amount is achieved ---> stop
        return 0;
    }
    int minNoCoin = INT_MAX;
    for (auto co:coins) {
        int ans = solve(coins,amount - co);   //get ans from every coin of the coinList

        if(ans != INT_MAX){                        //if the solution is possible (not more than we need)
            minNoCoin = min(minNoCoin, 1 + ans);   //1 for that coin and rest of the ans
        }
    }
    return minNoCoin;
}

int coinChange(vector<int>& coins, int amount) {
    int ans =  solve(coins,amount);
    if(ans == INT_MAX){                     //if it is not possible to make that amount of money by these coins
        return -1;
    }
    return ans;
}
int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout<<coinChange(coins,amount);
}