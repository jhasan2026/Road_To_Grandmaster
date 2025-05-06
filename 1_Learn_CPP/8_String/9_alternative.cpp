#include "iostream"

using namespace std;


int main(){
    string str;
    getline(cin,str);

    int n = str.length();

    string firstSub = str.substr(0,n/2);
    string secondSub = "";
    if(n&1){
        secondSub = str.substr(n/2+1);
    }
    else{
        secondSub = str.substr(n/2);
    }

    if(firstSub==secondSub){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not palindrome";
    }


}