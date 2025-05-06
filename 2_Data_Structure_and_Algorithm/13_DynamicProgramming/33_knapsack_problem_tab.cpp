#include "iostream"
#include "vector"

using namespace std;
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,0));

    for (int cap = weight[0]; cap <= maxWeight; ++cap) {            //for the last element where (index==0)
        if(weight[0] <= maxWeight){                         //if the weight is under capacity take it
            dp[0][cap] = value[0];                          //add its values
        }
    }

    for (int index = 1; index <= n; ++index){               //from 1ST ...... Nth element
        for (int cap = 0; cap <= maxWeight ; ++cap) {
            int include = 0;
            if(weight[index] <= cap){                                   //if the weight is under capacity take it
                include = value[index] +dp[index-1][cap - weight[index]];       //capacity -= weightOfTheProduct
            }

            int exclude = 0 + dp[index-1][cap];             //skip the element
            dp[index][cap]  = max(include,exclude);
        }
    }
    return dp[n-1][maxWeight];
}

int main(){
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    cout<<knapsack(weight,value,4,5);

}