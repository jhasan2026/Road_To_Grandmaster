#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    string findWord;
    cin>>findWord;

    int fn=findWord.length(),flag=0;

    for (int i = 0; i < str.length()-fn+1; ++i) {
        string temp = str.substr(i,fn);
        if(temp==findWord){
            cout<<"found at "<<i<<endl;
            flag=1;
        }
    }
    if(flag==0){
        cout<<"Not found";
    }





}