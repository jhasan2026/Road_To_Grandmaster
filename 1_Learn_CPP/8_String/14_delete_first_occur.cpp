#include "iostream"


using namespace std;

int main(){
    string str;
    getline(cin,str);

    int n=str.length();
    char c;
    cin>>c;
    for (int i = 0; i < n; ++i) {
        if(str[i]==c and i<n-1){
            for (int j = i; j < n; ++j) {
                str[j] = str[j+1];
            }
            n--;
            str[n] = '\0';
            break;
        }
    }
    cout<<str;




}