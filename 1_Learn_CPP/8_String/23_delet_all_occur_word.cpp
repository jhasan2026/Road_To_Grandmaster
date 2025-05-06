#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    string findWord;
    cin>>findWord;

    int fn=findWord.length();

    for (int i = 0; i < str.length()-fn+1; ++i) {
        string temp = str.substr(i,fn);
        if(temp==findWord){
            string firstPart = str.substr(0,i);
            string lastPart = str.substr(i+fn);
            str = firstPart + lastPart;
            i--;
        }
    }

    cout<<str;






}