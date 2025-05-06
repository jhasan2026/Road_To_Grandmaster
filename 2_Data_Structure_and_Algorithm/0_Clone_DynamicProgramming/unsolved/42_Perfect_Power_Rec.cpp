#include "iostream"
#include "vector"
#include "math.h"
#define MOD 1000000007
using namespace std;


int solve(int n,int x) {
    if(n==0){
        return 0;
    }
    int minOfWay=INT_MAX;
    for (int i = 1; pow(i,x) <=n ; ++i) {
        minOfWay = min(minOfWay,1 + (solve(n-pow(i,x),x)%MOD));
    }
    return minOfWay;
}
int numberOfWays(int n, int x) {
    return solve(n,x);
}

int main(){
    cout<<numberOfWays(10,2);
}