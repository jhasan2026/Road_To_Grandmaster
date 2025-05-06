#include "iostream"
#include "vector"

using namespace std;

bool checkLucky(int n){
    int temp = n;
    while (temp){
        if(temp % 10 != 4 && temp % 10 != 7){
            return false;
        }
        temp /= 10;
    }
    return true;
}

string solve(int n){
    for (int i = 2; i < n; ++i) {
        if(checkLucky(n)){
            return "YES";
        }
        else if(n%i==0 && checkLucky(i)){
            return "YES";
        }
    }
    return "NO";
}


int main(){
    int n;
    cin>>n;
    cout<<solve(n);
}