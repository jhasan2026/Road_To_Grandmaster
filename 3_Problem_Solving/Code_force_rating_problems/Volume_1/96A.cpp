#include "iostream"
#include "vector"

using namespace std;

string solve(string players){
    if(players.size() < 7){
        return "NO";
    }
    for (int i = 0; i < players.size()-6; ++i) {
        string subStr = players.substr(i,7);
        if(subStr=="0000000" || subStr=="1111111"){
            return "YES";
        }
    }
    return "NO";
}

int main(){
    string str;
    cin>>str;
    cout<<solve(str);
}