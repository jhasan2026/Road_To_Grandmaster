#include "iostream"
#include "vector"
using namespace std;


int solve(int n) {
    if(n==0){
        return 0;
    }
    int minOfWay=INT_MAX;
    for (int i = 1; i*i <=n ; ++i) {
        minOfWay = min(minOfWay,1 + solve(n-(i*i)));
    }
    return minOfWay;
}
int numSquares(int n) {
    return solve(n);
}

int main(){
    cout<<numSquares(12);
}