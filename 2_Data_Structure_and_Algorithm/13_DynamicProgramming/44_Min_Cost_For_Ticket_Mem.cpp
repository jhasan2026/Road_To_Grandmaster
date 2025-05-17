#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& days,int noOfDays, vector<int>& costs,int index,vector<int> &dp) {
    if(index >= days.size()){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int oneDayCost = costs[0] + solve(days,noOfDays,costs,index+1,dp);
    int i = 0;
    for (i= index; (i < noOfDays) && (days[i] < days[index] + 7) ; ++i);
    int sevenDayCost = costs[1] + solve(days,noOfDays,costs,i,dp);

    for (i= index; (i < noOfDays) && (days[i] < days[index] + 30) ; ++i);
    int thirtyDayCost = costs[2] + solve(days,noOfDays,costs,i,dp);
    return dp[index] = min(oneDayCost, min(sevenDayCost,thirtyDayCost));
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n+1,-1);
    return solve(days,n,costs,0,dp);
}


int main(){
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout<<mincostTickets(days,costs);
}