#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


int solve(vector<pair<int,int>> list,int currIndex,int prevIndex,vector<vector<int>> &dp) {
    if(currIndex >= list.size()){
        return 0;
    }
    if(dp[currIndex][prevIndex+1] != -1){
        return dp[currIndex][prevIndex+1];
    }
    int include = 0;
    if(prevIndex==-1 || list[currIndex].second > list[prevIndex].second){
        include = 1 + solve(list,currIndex+1,currIndex,dp);
    }
    int exclude = 0 + solve(list,currIndex+1,prevIndex,dp);
    return dp[currIndex][prevIndex+1] = max(include,exclude);
}


int maxEnvelopes(vector<vector<int>>& envelopes) {
    vector<pair<int,int>> list;
    for (int i = 0; i < envelopes.size(); ++i) {
        list.push_back({envelopes[i][0], envelopes[i][1]});
    }
    sort(list.begin(), list.end(), [](const pair<int, int>& env1, const pair<int, int>& env2) {
        if (env1.first == env2.first) {
            return env1.second > env2.second;
        }
        return env1.first < env2.first;
    });
    int n = envelopes.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    return solve(list,0,-1,dp);
}


int main(){
    vector<vector<int>> envelopes = {{5, 4},
                                     {6, 4},
                                     {6, 7},
                                     {2, 3}};
    cout<<maxEnvelopes(envelopes);
}