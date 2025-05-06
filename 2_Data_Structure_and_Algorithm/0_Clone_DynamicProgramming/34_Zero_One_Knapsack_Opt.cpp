#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,-1));
    vector<int> prev(maxWeight+1,0);
    vector<int> curr(maxWeight+1,0);
    for (int i = weight[0]; i <= maxWeight; ++i) {
        if(weight[0] <= maxWeight) {
            prev[i] = value[0];
        }
    }

    for (int index = 1; index <= n; ++index) {
        for (int cap = 0; cap <= maxWeight; ++cap) {
            int include = 0;
            if(weight[index] <= cap){
                include = value[index]  + prev[cap-weight[index]];
            }
            int exclude = 0 + prev[cap];
            curr[cap] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    int ans = solve(weight,value,n,maxWeight);
    if(ans == -1){
        return 0;
    }
    return ans;
}

int main(){
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    cout<<knapsack(weight,value,4,5);
}