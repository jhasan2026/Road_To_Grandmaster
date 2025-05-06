#include "iostream"
#include "vector"

using namespace std;

string longestPrefix(string word1,string word2){
    int i=0,j=0;
    while (i<word1.length() && j<word2.length()){
        if(word1[i]!=word2[j]){
            break;
        }
        i++;
        j++;
    }
    return word1.substr(0,i);
}

string longestCommonOPrefix(vector<string> &list){
    string commonPrefix=list[0];
    for (auto word:list) {
        commonPrefix= longestPrefix(commonPrefix,word);
    }
    return commonPrefix;
}

int main(){
    vector<string> vStr={
            "techie delight","tech","techie","technology","technical"
    };
    cout<<longestCommonOPrefix(vStr)<<endl;
}