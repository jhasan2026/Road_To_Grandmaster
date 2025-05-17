#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool checkUpLow(vector<int> &baseBox,vector<int> &upBox){
    if((baseBox[0] >= upBox[0]) &&(baseBox[1] >= upBox[1]) && (baseBox[2] >= upBox[2])){
        return true;
    }
    return false;
}

int solve(vector<vector<int>>& cuboids,int currIndex,int prevIndex,vector<vector<int>> &dp) {
    if(currIndex >= cuboids.size()){
        return 0;
    }
    if(dp[currIndex][prevIndex+1] != -1){
        return dp[currIndex][prevIndex+1];
    }
    int include = 0;
    if(prevIndex == -1 || checkUpLow(cuboids[currIndex],cuboids[prevIndex])){
        include = cuboids[currIndex][2] + solve(cuboids,currIndex+1,currIndex,dp);
    }
    int exclude = 0 + solve(cuboids,currIndex+1,prevIndex,dp);
    return dp[currIndex][prevIndex+1] =  max(include,exclude);
}

int maxHeight(vector<vector<int>>& cuboids) {
    for (auto &eachRow:cuboids) {
        sort(eachRow.begin(), eachRow.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int n= cuboids.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(cuboids,0,-1,dp);
}

int main(){
    vector<vector<int>> cuboids = {{50, 45, 20},
                                   {95, 37, 53},
                                   {45, 23, 12}};
    cout<<maxHeight(cuboids);
}