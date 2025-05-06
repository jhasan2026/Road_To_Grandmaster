#include "iostream"
//#include "string"

using namespace std;
int main(){
    string str1;
    getline(cin,str1);
    int i=0,idk=0;
    char ch,rep;
    cin>>ch>>rep;
    while (str1[i]){
        if(str1[i]==ch){
            idk=i;
        }
        i++;
    }
    str1[idk]=rep;
    cout<<str1;
}