#include "iostream"
#include "vector"

using namespace std;

int minDistance(string word1, string word2) {
    int n=word1.size(), m = word2.size();

    if(m==0){
        return n;
    }

    vector<int> next(m+1,0);
    vector<int> curr(m+1,0);


    for (int j = 0; j < m; ++j) {
        next[j] = word2.length() - j;
    }


    for (int i = n-1; i >=0 ; --i) {
        for (int j = m-1; j >=0 ; --j) {

            curr[m] = word1.length()-i;

            int ans = 0;
            if(word1[i] == word2[j]){
                ans = next[j+1];     //if match two char both i++ and j++ and return 0
            }
            else{
                //Do everything in the 1st word
                int insertAns = 1 + curr[j+1];    //if insert :: deactivate one letter for word1 and j++

                int deleteAns = 1 + next[j];    //if delete :: deactivate one letter for word2 ans i++

                int replaceAns = 1 + next[j+1];  //if replace both i++ and j++ and return 1

                ans = min(insertAns,min(deleteAns,replaceAns));
            }
            curr[j] = ans;
        }
        next = curr;
    }

    return next[0];
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