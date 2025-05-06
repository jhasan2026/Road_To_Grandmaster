#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);
    cout<<"find:";
    char c;
    cin>>c;

    int index = -1;
    for (int i = 0; i < str.length(); ++i) {
        if(c==str[i]){
            cout<<i<<" ";
            index = 0;
        }
    }
    if(index==-1){
        cout<<"Not found";
    }


}