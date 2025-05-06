#include "iostream"
#include "vector"

using namespace std;

int solve(int x){
    int count = 0;
    for (int i = 5; i >= 2; --i) {
        count += x/i;
        x = x%i;
    }
    return count + x;
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n);
}