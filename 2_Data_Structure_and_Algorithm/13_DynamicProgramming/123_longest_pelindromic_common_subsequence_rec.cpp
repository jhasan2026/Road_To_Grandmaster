#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int solve(string text1, string text2,int i,int j) {
    if(i >= text1.size() || j>= text2.size()){
        return 0;
    }

    int ans = 0;
    if(text1[i] == text2[j]){                                // both char is same -> go on for both string i++ and j++
        ans = 1 + solve(text1,text2,i+1,j+1);
    }
    else{
        ans = max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1)); // if not match :: get max from either i++ or j++
                                                                        //i++ mean go on in the first string
    }
    return ans;

}
int longestPalindromeSubseq(string s) {
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    return solve(s,revStr,0,0);
}

int main(){
    string text = "bbbab";
    cout<<longestPalindromeSubseq(text);
}