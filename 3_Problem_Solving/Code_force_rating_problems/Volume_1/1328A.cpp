#include <bits/stdc++.h>

using namespace std;

int solve(int a,int b){
    int up = ceil((float )a/b);
    return up*b - a;
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        cout << solve(a, b)<<endl;
    }
}


