#include "iostream"

using namespace std;

bool checkPalindrome(string str,int i,int j){
    if(str[i]!=str[j]){
        return false;
    }
    if(i>=j){
        return true;
    }
    return checkPalindrome(str,i+1,j-1);
}

int main(){
    string str = "qwertyuytrewq";
    cout<<checkPalindrome(str,0,str.length()-1);
}