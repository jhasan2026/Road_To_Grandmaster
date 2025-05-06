#include "iostream"
#include "cctype"

using namespace std;

int main(){
    string str;
    getline(cin,str);

    for (char &c:str) {
        if(c>='a' && c<='z'){
            c -= 32;
        }
    }
    cout<<str;



}