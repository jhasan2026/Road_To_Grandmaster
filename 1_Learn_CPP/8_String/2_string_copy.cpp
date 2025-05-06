#include "iostream"

using namespace std;

int main(){
    string str,str2;
    getline(cin,str);
    getline(cin,str2);

    string copy1,copy2;
    copy1 = str;
    copy2 = str2;

    str[0] = 'A';
//    copy1[0] = 'C';

    cout<<copy1<<endl<<copy2;
}