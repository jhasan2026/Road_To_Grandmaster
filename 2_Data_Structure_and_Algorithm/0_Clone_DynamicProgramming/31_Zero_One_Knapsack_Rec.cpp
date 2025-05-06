#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int> weight, vector<int> value, int n, int maxWeight,int index){
    if(index==n-1){
        if(weight[index] <= maxWeight){
            return value[index];
        }
        else{
            return 0;
        }
    }
    int include = 0;
    if(weight[index] <= maxWeight){
        include = value[index] + solve(weight,value,n,maxWeight-weight[index],index+1);
    }
    int exclude = 0 + solve(weight,value,n,maxWeight,index+1);
    return max(include, exclude);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    return solve(weight,value,n,maxWeight,0);
}

int main(){
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    cout<<knapsack(weight,value,4,5);
}