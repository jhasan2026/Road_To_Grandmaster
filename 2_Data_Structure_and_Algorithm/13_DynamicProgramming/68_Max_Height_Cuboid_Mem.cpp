#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

bool check(vector<int> base,vector<int> newBox){
    return (base[0] >= newBox[0]) && (base[1] >= newBox[1]) && (base[2] >= newBox[2]);
}

int solve(vector<vector<int>>& cuboids,int curr,int prev,vector<vector<int>> &dp) {
    if(curr == cuboids.size()){
        return 0;
    }

    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }

    int include = 0;
    if(prev==-1 || check(cuboids[curr],cuboids[prev])){
        include = cuboids[curr][2] + solve(cuboids,curr+1,curr,dp);
    }
    int exclude = 0 + solve(cuboids,curr+1,prev,dp);
    return dp[curr][prev+1] =  max(include,exclude);
}

int maxHeight(vector<vector<int>>& cuboids) {
    for (auto &eachBox:cuboids) {
        sort(eachBox.begin(), eachBox.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int n= cuboids.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(cuboids,0,-1,dp);
}

int main(){
    vector<vector<int>> cuboids = {{36, 46,  41},
                                   {15, 100, 100},
                                   {75, 91,  59},
                                   {13, 82,  64}};
    cout<<maxHeight(cuboids);
}