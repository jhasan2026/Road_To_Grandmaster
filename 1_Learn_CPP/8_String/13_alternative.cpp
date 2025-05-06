#include "iostream"
#include "vector"
#define MOD 1007


using namespace std;

int main(){
    string str;
    getline(cin,str);

    int n=str.length();
    vector<int> frq(MOD,0);
    for (int i = 0; i < n; ++i) {
        int ch = str[i];
        (frq[ch%MOD])++;
    }


    for (int i = 0; i < MOD; ++i) {
        if(frq[i]!=0){
            char ch = i;
            cout<<ch<<"--->"<<frq[i]<<endl;
        }
    }




}