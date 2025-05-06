#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

string capsLockOn(string str){
    for (int i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
    str[0] = toupper(str[0]);
    return str;
}

bool checkLower(char c){
    return c >= 'a' && c <= 'z';
}

string solve(string str){
    if(str.size() == 1){
        if(checkLower(str[0])){
            return capsLockOn(str);
        }
        str[0] = tolower(str[0]);
        return str;
    }
    for (int i = 1; i < str.size(); ++i) {
        if(checkLower(str[i])){
            return str;
        }
    }
    if(checkLower(str[0])){
        return capsLockOn(str);
    }
    string ans = capsLockOn(str);
    ans[0] = tolower(ans[0]);
    return ans;

}

int main(){
    string str;
    cin>>str;
    cout<<solve(str);
}