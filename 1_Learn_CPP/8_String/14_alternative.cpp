#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    char c;
    cin>>c;
    int index = str.find(c);
    string firstSub = str.substr(0,index);
    string secondSub = str.substr(index+1);
    str = firstSub + secondSub;
    cout<<str;


}