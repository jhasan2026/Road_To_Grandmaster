#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

   string rev = "";

    for (int i = str.length()-1; i >=0 ; --i) {
        rev+=str[i];
    }

    cout<<rev;

}