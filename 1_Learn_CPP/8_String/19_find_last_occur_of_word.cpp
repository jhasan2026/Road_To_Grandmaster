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
            index=i;
        }
    }
    if(index==-1){
        cout<<"Not found";
    }
    else{
        cout<<"found at "<<index;
    }




}