#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

string solve(string string1,string string2){
    if(string1.size() != string2.size()){
        return "NO";
    }
    reverse(string2.begin(), string2.end());
    if(string1 == string2){
        return "YES";
    }
    return "NO";
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    cout<<solve(str1,str2);
}