#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    int alpha=0,dig=0,oth=0;
    for (char &c:str) {
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            alpha++;
        }
        else if(c>='0' && c<='9'){
            dig++;
        }
        else{
            oth++;
        }
    }

    cout<<alpha<<" "<<dig<<" "<<oth;



}