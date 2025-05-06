
#include "iostream"

using namespace std;

void charTypeCheck(char c){
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E',c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
        cout<<"Vowel"<<endl;
    }
    else if(c >= '0' && c<='9'){
        cout<<"Digit"<<endl;
    }
    else{
        cout<<"Consonant"<<endl;
    }
}

int main(){
    charTypeCheck('f');
    charTypeCheck('u');
}