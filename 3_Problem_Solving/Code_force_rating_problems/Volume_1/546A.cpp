#include "iostream"
#include "vector"

using namespace std;

int solve(int k,int n,int w){
    int ans = ((w+1)*k*w)/2 - n;
    return max(0,ans);
}

int main(){
    int k,n,w;
    cin>>k>>n>>w;
    cout<<solve(k,n,w);
}