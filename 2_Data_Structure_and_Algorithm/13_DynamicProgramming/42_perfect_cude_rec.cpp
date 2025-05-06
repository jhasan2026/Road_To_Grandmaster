#include "iostream"

using namespace std;

int solve(int n){
    if(n==0){       //condition is satisfied -> return with sum 0
        return 0;
    }
    int minCounter = n;
    for (int i = 1; i*i*i <= n; ++i) {
        minCounter = min(minCounter,1 +solve(n-i*i*i)); //1 for that step and rest of the solution is f(n - i^3)
    }
    return minCounter;
}

int numCube(int n) {
    return solve(n);
}

int main(){
    cout<<numCube(12);
}