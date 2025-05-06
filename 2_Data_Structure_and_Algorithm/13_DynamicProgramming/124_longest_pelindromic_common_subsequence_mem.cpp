#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int solve(string text1, string text2,int i,int j,vector<vector<int>> &dp) {
    if(i >= text1.size() || j>= text2.size()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(text1[i] == text2[j]){                                // both char is same -> go on for both string i++ and j++
        ans = 1 + solve(text1,text2,i+1,j+1,dp);
    }
    else{
        ans = max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp)); // if not match :: get max from either i++ or j++
        //i++ mean go on in the first string
    }
    return dp[i][j] = ans;

}
int longestPalindromeSubseq(string s) {
    int n = s.size();
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(s,revStr,0,0,dp);
}

int main(){
    string text = "bbbab";
    cout<<longestPalindromeSubseq(text);
}