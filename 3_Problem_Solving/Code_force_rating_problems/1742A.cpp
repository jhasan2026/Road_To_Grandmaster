#include "iostream"
#include "vector"
#include "math.h"
#include "algorithm"
using namespace std;

string solve(int a,int b,int c){
    if(a+b == c){
        return "YES";
    }
    if(b+c == a){
        return "YES";
    }
    if(a+c == b){
        return "YES";
    }
    return "NO";
}

int main(){

    int n, a,b,c;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a>>b>>c;
        cout<<solve(a,b,c)<<endl;
    }


}