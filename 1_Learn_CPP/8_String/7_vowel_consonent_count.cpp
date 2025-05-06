#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    int vow=0,conso=0;
    for (char &c:str) {
        if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U'){
            vow++;
        }
        else if(c==' ');
        else{
            conso++;
        }
    }

    cout<<conso<<" "<<vow;



}