#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    string findWord;
    cin>>findWord;

    int fn=findWord.length(),index=-1;

    for (int i = 0; i < str.length()-fn+1; ++i) {
        string temp = str.substr(i,fn);
        if(temp==findWord){
            index = i;
        }
    }

    if(index!=-1){
        string firstPart = str.substr(0,index);
        string lastPart = str.substr(index+fn);
        str = firstPart + lastPart;
    }

    cout<<str;






}