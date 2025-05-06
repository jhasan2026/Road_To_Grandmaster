#include "iostream"


using namespace std;
int main(){
    string str1;
    getline(cin,str1);
    int len=str1.length(),uni[len];
    for (int i = 0; i < len; ++i) {
        uni[i]=-1;
    }
    for (int i = 0; i < len; ++i) {
        int count=1;
        for (int j = i+1; j < len; ++j) {
            if(str1[i]==str1[j]){
                count++;
                uni[j]=0;
            }
        }
        if(uni[i]!=0){
            uni[i]=count;
        }
    }
    int i = 0;
    for (; i < len; ++i) {
        if(uni[i]==0){
            for (int j = i; j < len; ++j) {
                str1[j]=str1[j+1];
            }
            len--;
        }
    }
    str1[i]='\0';
    cout<<str1;

}