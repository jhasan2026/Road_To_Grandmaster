#include "iostream"

using namespace std;

int main(){
    string str,str2;
    getline(cin,str);
    getline(cin,str2);

    string sumStr = str + str2;
    cout<<sumStr;
}