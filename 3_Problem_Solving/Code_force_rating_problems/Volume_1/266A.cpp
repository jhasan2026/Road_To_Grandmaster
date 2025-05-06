#include "iostream"

using namespace std;

int solve(int n,string colors){
    if(n==1){
        return 0;
    }
    int count = 0;
    for (int i = 0; i < n-1; ++i) {
        if(colors[i] == colors[i+1]){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    cout<<solve(n,str);
}