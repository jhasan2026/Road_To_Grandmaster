#include "iostream"
#include "vector"

using namespace std;


int solve(string word1, string word2,int i,int j) {
    if(i==word1.length()){
        return word2.length()-j;
    }

    if(j==word2.length()){
        return word1.length()-i;
    }

    int ans = 0;
    if(word1[i] == word2[j]){
        return 0 + solve(word1,word2,i+1,j+1);     //if match two char both i++ and j++ and return 0
    }
    else{
        //Do everything in the 1st word
        int insertAns = 1 + solve(word1,word2,i,j+1);    //if insert :: deactivate one letter for word1 and j++

        int deleteAns = 1 + solve(word1,word2,i+1,j);    //if delete :: deactivate one letter for word2 ans i++

        int replaceAns = 1 + solve(word1,word2,i+1,j+1);  //if replace both i++ and j++ and return 1

        ans = min(insertAns,min(deleteAns,replaceAns));
    }
    return ans;
}

int minDistance(string word1, string word2) {
    return solve(word1,word2,0,0);
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