#include "iostream"
#include "vector"
#include "math.h"
using namespace std;
int solve(int n){
    if(n%2 == 1){
        return n/2;
    }
    return n/2 - 1;
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        cout<<solve(x)<<endl;
    }
}