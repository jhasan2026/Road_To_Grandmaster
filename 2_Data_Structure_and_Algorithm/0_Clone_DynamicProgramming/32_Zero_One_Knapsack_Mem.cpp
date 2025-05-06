#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int> weight, vector<int> value, int n, int maxWeight,int index,vector<vector<int>> &dp){
    if(index==n-1){
        if(weight[index] <= maxWeight){
            return value[index];
        }
        else{
            return 0;
        }
    }
    if(dp[index][maxWeight] != -1){
        return dp[index][maxWeight];
    }
    int include = 0;
    if(weight[index] <= maxWeight){
        include = value[index] + solve(weight,value,n,maxWeight-weight[index],index+1,dp);
    }
    int exclude = 0 + solve(weight,value,n,maxWeight,index+1,dp);
    return dp[index][maxWeight] = max(include, exclude);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,-1));
    return solve(weight,value,n,maxWeight,0,dp);
}

int main(){
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    cout<<knapsack(weight,value,4,5);
}