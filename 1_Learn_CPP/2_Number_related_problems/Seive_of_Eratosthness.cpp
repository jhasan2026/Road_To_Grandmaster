#include "iostream"
#include "vector"
#include "math.h"
#include "algorithm"
using namespace std;

void makeCheckPrime(int maxi,vector<bool> &checkPrime){
    checkPrime[0] = checkPrime[1] = false;
    for (int i = 2; i*i <= maxi; ++i) {
        if(checkPrime[i]) {
            for (int j = i * i; j <= maxi; j += i) {
                checkPrime[j] = false;
            }
        }
    }
}



int main(){
    int n,maxi=0;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        maxi = max(maxi, arr[i]);
    }
    vector<bool> checkPrime(maxi+1, true);
    makeCheckPrime(maxi, checkPrime);
    for (int i = 0; i < n; ++i) {
        if(checkPrime[arr[i]]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}