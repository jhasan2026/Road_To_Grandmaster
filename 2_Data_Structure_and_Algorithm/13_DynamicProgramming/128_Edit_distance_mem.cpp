#include "iostream"
#include "vector"

using namespace std;


int solve(string word1, string word2,int i,int j,vector<vector<int>> &dp) {
    if(i==word1.length()){
        return word2.length()-j;
    }

    if(j==word2.length()){
        return word1.length()-i;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(word1[i] == word2[j]){
        return  dp[i][j] =  solve(word1,word2,i+1,j+1,dp);     //if match two char both i++ and j++ and return 0
    }
    else{
        //Do everything in the 1st word
        int insertAns = 1 + solve(word1,word2,i,j+1,dp);    //if insert :: deactivate one letter for word1 and j++

        int deleteAns = 1 + solve(word1,word2,i+1,j,dp);    //if delete :: deactivate one letter for word2 ans i++

        int replaceAns = 1 + solve(word1,word2,i+1,j+1,dp);  //if replace both i++ and j++ and return 1

        ans = min(insertAns,min(deleteAns,replaceAns));
    }
    return dp[i][j] = ans;
}

int minDistance(string word1, string word2) {
    int n=word1.size(), m = word2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return solve(word1,word2,0,0,dp);
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