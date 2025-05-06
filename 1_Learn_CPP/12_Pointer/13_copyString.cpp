#include "iostream"


using namespace std;
int main(){
    char str[100],copy[100];
    cin.get(str,100);
    int i=0;
    while (*(str+i)!='\0'){
        *(copy+i)=*(str+i);
        i++;
    }
    *(str+i)='\0';
    i=0;
    while (*(str+i)!='\0'){
        cout<<*(str+i);
        i++;
    }


}

