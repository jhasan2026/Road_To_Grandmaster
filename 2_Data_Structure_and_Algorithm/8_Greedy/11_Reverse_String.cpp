#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
string reverseString(string str){
    string ans="";
    string temp="";
    for (int i = str.length()-1; i >=0 ; --i) {
        if(str[i]== ' '){
            reverse(temp.begin(), temp.end());
            ans+=temp;
            ans.push_back(' ');
            temp="";
        }
        else{
            temp.push_back(str[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    ans+=temp;
    return ans;
}

int main(){
    cout<<reverseString("I love Real Madrid")<<endl;
}