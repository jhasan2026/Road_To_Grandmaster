#include "iostream"


using namespace std;
int main(){
    char str1[100],str2[100],str[200];
    cin.getline(str1,100);
    cin.getline(str2,100);
    int i=0;
    while (*(str1+i)!='\0'){
        str[i]=str1[i];
        i++;
    }
    int j=0;
    while (*(str2+j)!='\0'){
        str[i]=str2[j];
        i++;
        j++;
    }
    str[i]='\0';
    i=0;
    while (*(str+i)!='\0'){
        cout<<*(str+i);
        i++;
    }


}

