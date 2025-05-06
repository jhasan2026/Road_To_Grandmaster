#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    int n=str.length();
    int  frq[n];
    for (int i = 0; i < n; ++i) {
        frq[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        int count = 1;
        for (int j = i+1; j < n; ++j) {
            if(str[i]==str[j]){
                count++;
                frq[j] = 0;
            }
        }
        frq[i] = count;
    }

    for (int i = 0; i < n; ++i) {
        if(frq[i]!=0){
            cout<<str[i]<<"--->"<<frq[i]<<endl;
        }
    }




}