#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    int n=str.length(),index=-1;
    char c;
    cin>>c;
    for (int i = 0; i < n; ++i) {
        if(str[i]==c){
           index = i;
        }
    }
    if(index!=-1){
        for (int j = index; j < n; ++j) {
            str[j] = str[j+1];
        }
        n--;
        str[n] = '\0';

    }
    cout<<str;




}