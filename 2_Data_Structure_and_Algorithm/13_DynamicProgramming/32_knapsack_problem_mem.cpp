#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int> weight, vector<int> value, int maxWeight,int index,vector<vector<int>> &dp)
{
    if(index == 0){                     //for the last element
        if(weight[0] <= maxWeight){          //if the weight is under capacity take it
            return value[0];                 //add its values
        }
        else{
            return 0;
        }
    }

    if(dp[index][maxWeight]!=-1){
        return dp[index][maxWeight];
    }


    int include = 0;
    if(weight[index] <= maxWeight){                                                 //if the weight is under capacity take it
        include = value[index] + solve(weight,value,maxWeight-weight[index],index-1,dp);         //capacity -= weightOfTheProduct
    }

    int exclude = 0 + solve(weight,value,maxWeight,index-1,dp);              //skip the element
    return dp[index][maxWeight]  = max(include,exclude);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,-1));
    return solve(weight,value,maxWeight,n-1,dp);                            //from n-1 ...... 0th element
}

int main(){
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    cout<<knapsack(weight,value,4,5);

}