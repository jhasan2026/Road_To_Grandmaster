#include "iostream"
#include "vector"

using namespace std;

string solve(long long n){
    int cnt = 0;
    while (n){
        if(n%10 == 4 || n%10==7){
            cnt++;
        }
        n /= 10;
    }
    if(cnt == 4 || cnt == 7){
        return "YES";
    }
    return "NO";
}

int main(){
    long long n;
    cin>>n;
    cout<<solve(n);
}