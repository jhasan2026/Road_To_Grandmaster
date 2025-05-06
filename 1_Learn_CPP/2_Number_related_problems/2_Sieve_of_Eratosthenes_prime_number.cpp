
#include "iostream"
#include "vector"
using namespace std;

bool primeNumberCheck(int n){
    vector<int> primeList(n+1,0);
    for (int i = 2; i <= n; ++i) {
        if(primeList[i] == 0){
            for (int j = i*i; j <= n ; j+=i) {
                primeList[i] = 1;
            }
        }
    }
    if(primeList[n] == 0){
        return true;
    }
    return false;
}

int main(){
    cout<<primeNumberCheck(41)<<endl;
}