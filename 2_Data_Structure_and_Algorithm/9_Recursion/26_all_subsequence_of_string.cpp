#include "iostream"
#include "vector"

using namespace std;

void findAllSubsequenceSolve(string str,int index,string sub,vector<string> &ans){
    if(index >= str.size()){
        ans.push_back(sub);
        return;
    }

    //exclude
    findAllSubsequenceSolve(str,index+1,sub,ans);

    // include
    char c = str[index];
    sub += c;
    findAllSubsequenceSolve(str,index+1,sub,ans);

}

vector<string> findALlSubsequence(string str){
    vector<string> ans;
    string sub;

    findAllSubsequenceSolve(str,0,sub,ans);
    return ans;
}

int main(){
    string  str = "abc";
    vector<string> subsets = findALlSubsequence(str);

    for (auto x:subsets) {
        cout<<x<<endl;
    }
}