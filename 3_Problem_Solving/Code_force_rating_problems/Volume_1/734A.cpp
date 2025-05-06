#include "iostream"
#include "vector"

using namespace std;

string solve(int n,string str){
    int anton=0, danik =0;
    for (int i = 0; i < n; ++i) {
        if(str[i] == 'A'){
            anton++;
        }
        else{
            danik++;
        }
    }
    if(anton == danik){
        return "Friendship";
    }
    else if(anton > danik){
        return "Anton";
    }
    return "Danik";
}

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    cout<<solve(n,str);
}