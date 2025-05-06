#include "iostream"

using namespace std;
int main(){
    string str,word;
    getline(cin,str);
    getline(cin,word);
    int idk=-1;
    for (int i = 0; i < str.length()-word.length(); ++i) {
        int check=0;
        for (int j = 0; j < word.length(); ++j) {
            if(str[i+j]!=word[j]){
                check=1;
                break;
            }
        }
        if(check==0){
            idk=i;
            break;
        }
    }
    if(idk==-1){
        cout<<"Not found";
    }else{
        cout<<idk;
    }

}