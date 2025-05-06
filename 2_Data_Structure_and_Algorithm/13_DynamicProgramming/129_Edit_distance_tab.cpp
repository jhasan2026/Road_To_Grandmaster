#include "iostream"
#include "vector"

using namespace std;

int minDistance(string word1, string word2) {
    int n=word1.size(), m = word2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int j = 0; j < m; ++j) {
        dp[n][j] = word2.length() - j;
    }
    for (int i = 0; i < n; ++i) {
        dp[i][m] = word1.length() - i;
    }

    for (int i = n-1; i >=0 ; --i) {
        for (int j = m-1; j >=0 ; --j) {
            int ans = 0;
            if(word1[i] == word2[j]){
                ans = dp[i+1][j+1];     //if match two char both i++ and j++ and return 0
            }
            else{
                //Do everything in the 1st word
                int insertAns = 1 + dp[i][j+1];    //if insert :: deactivate one letter for word1 and j++

                int deleteAns = 1 + dp[i+1][j];    //if delete :: deactivate one letter for word2 ans i++

                int replaceAns = 1 + dp[i+1][j+1];  //if replace both i++ and j++ and return 1

                ans = min(insertAns,min(deleteAns,replaceAns));
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int main(){
    string word1 = "intention", word2 = "execution";
    cout<<minDistance(word1,word2);

//    Explanation:
//    intention -> inention (remove 't')
//    inention -> enention (replace 'i' with 'e')
//    enention -> exention (replace 'n' with 'x')
//    exention -> exection (replace 'n' with 'c')
//    exection -> execution (insert 'u')
}