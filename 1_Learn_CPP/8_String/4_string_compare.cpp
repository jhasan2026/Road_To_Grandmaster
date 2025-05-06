#include "iostream"

using namespace std;

int main(){
    string str,str2;
    getline(cin,str);
    getline(cin,str2);

    if(str == str2){
        cout<<"Both are same";
    }
    else if(str < str2){
        cout<<"string1 is less than string2";
    }
    else{
        cout<<"string1 is greater than string2";
    }
}