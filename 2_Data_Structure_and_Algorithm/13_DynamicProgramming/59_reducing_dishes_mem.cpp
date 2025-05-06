#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int solve(vector<int>& satisfaction,int index,int time,vector<vector<int>> &dp) {
    if(index == satisfaction.size()){
        return 0;
    }

    if(dp[index][time] != -1){
        return dp[index][time];
    }

    int include = satisfaction[index]*(time+1) + solve(satisfaction,index+1,time+1,dp);  //if chef make the food -> time will be increase
    int exclude = 0 + solve(satisfaction,index+1,time,dp);     //if not -> time remain same
    return dp[index][time] =  max(include,exclude);
}

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());            //sort it into ascending -> more time more satisfaction (*)
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(satisfaction,0,0,dp);
}

int main(){
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout<<maxSatisfaction(satisfaction);
}