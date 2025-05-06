#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    int n = str.length()-1;

    int i=0,flag=0;
    while (str[i]!='\0'){
        if(str[i]!=str[n-i]){
            flag=1;
            break;
        }
        if(i>=n/2){
            break;
        }
        i++;
    }
    if(flag==0){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not a palindrome";
    }

}