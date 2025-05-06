#include "iostream"
#include "cctype"

using namespace std;

int main(){
    string str;
    getline(cin,str);

    for (char &c:str) {
        c = toupper(c);
    }
    cout<<str;



}