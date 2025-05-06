#include "iostream"
#include "vector"

using namespace std;

string upLow(int pin,string str){
    if(pin == 0){
        for (int i = 0; i < str.size(); ++i) {
            str[i] = tolower(str[i]);
        }
        return str;
    }
    for (int i = 0; i < str.size(); ++i) {
        str[i] = toupper(str[i]);
    }
    return str;
}

string solve(string str){
    int up =0 ,low = 0;
    for (int i = 0; i < str.size(); ++i) {
        if(str[i]>='a' && str[i] <='z'){
            low++;
        }
        else{
            up++;
        }
    }
    if(up <= low){
        return upLow(0,str);
    }
    return upLow(1,str);

}

int main(){
    string str;
    cin>>str;
    cout<<solve(str);
}