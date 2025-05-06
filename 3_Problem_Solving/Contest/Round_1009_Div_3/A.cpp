#include "iostream"
#include "vector"
#include "math.h"

using namespace std;

string solve(int l,int r,int d,int u){
   float a = sqrt(r*r + u*u);
   float b = sqrt(l*l + d*d);
   float c = sqrt(l*l + u*u);
   float e = sqrt(r*r + d*d);
   if (a == b && b == c && c==e && e==a){
       return "YES";
   }
    return "NO";
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int l,r,d,u;
        cin>>l>>r>>d>>u;
        cout<<solve(l,r,d,u)<<endl;
    }
}