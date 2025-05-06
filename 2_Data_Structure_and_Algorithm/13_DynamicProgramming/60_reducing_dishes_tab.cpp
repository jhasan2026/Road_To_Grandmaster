#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());            //sort it into ascending -> more time more satisfaction (*)
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for (int index = n-1; index >=0 ; --index) {
        for (int time = n-1; time >=0 ; --time) {
            int include = satisfaction[index]*(time+1) + dp[index+1][time+1];  //if chef make the food -> time will be increase
            int exclude = 0 + dp[index+1][time];     //if not -> time remain same
            dp[index][time] =  max(include,exclude);
        }
    }
    return dp[0][0];
}

int main(){
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout<<maxSatisfaction(satisfaction);
}