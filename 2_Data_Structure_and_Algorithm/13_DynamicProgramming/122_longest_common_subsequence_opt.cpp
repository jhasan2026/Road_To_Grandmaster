#include "iostream"
#include "vector"

using namespace std;


int longestCommonSubsequence(string text1, string text2) {
    int n=text1.size(),m=text2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    vector<int> next(m+1,0);
    vector<int> curr(m+1,0);

    for (int i = n-1; i >= 0; --i) {
        for (int j = m-1; j >= 0; --j) {
            int ans = 0;
            if(text1[i] == text2[j]){                                // both char is same -> go on for both string i++ and j++
                ans = 1 + next[j+1];
            }
            else{
                ans = max(next[j],curr[j+1]); // if not match :: get max from either i++ or j++
                                             //i++ mean go on in the first string
            }
            curr[j] = ans;
        }
        next = curr;
    }

    return next[0];
}

int main(){
    string text1 = "abcde", text2 = "ace";
    cout<<longestCommonSubsequence(text1,text2);
}