#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;




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
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for (int currIndex = n-1; currIndex >=0 ; --currIndex) {
        for (int prevIndex = currIndex-1; prevIndex >=-1 ; --prevIndex) {
            int include = 0;
            if(prevIndex==-1 || list[currIndex].second > list[prevIndex].second){
                include = 1 + dp[currIndex+1][currIndex+1];
            }
            int exclude = 0 + dp[currIndex+1][prevIndex+1];
            dp[currIndex][prevIndex+1] = max(include,exclude);
        }
    }

    return dp[0][0];
}


int main(){
    vector<vector<int>> envelopes = {{5, 4},
                                     {6, 4},
                                     {6, 7},
                                     {2, 3}};
    cout<<maxEnvelopes(envelopes);
}