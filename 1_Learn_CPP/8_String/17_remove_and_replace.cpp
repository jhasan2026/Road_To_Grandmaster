#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    int n=str.length();
    char c;
    cin>>c;
    char replace ;
    cin>>replace;
    for (int i = 0; i < n; ++i) {
        if(str[i]==c){
            str[i] = replace;
        }
    }
    cout<<str;




}