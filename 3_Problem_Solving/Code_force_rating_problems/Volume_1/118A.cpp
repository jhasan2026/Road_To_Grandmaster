#include "iostream"
#include "vector"

using namespace std;

string solve(string str){
    string ans = "";
    for (int i = 0; i < str.size(); ++i) {
        if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u' || str[i] == 'y'){
            continue;
        }
        ans += '.';
        ans += str[i];
    }
    return ans;
}

int main(){
    string str;
    cin>>str;
    for (int i = 0; i < str.size(); ++i) {
        str[i] = tolower(str[i]);
    }
    cout<<solve(str);
}