#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);
    cout<<"find:";
    char c;
    cin>>c;

    int flag=0;
    for (int i = 0; i < str.length(); ++i) {
        if(c==str[i]){
            cout<<i;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Not found";
    }


}