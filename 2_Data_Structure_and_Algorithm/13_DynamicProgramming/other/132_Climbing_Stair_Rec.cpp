#include "iostream"
#include "vector"
using namespace std;





int solve(int n) {
    if(n==0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    int oneStairJump = solve(n-1);
    int twoStairJump = solve(n-2);
    return oneStairJump + twoStairJump;
}

int climbStairs(int n) {
    return solve(n);
}
int main(){
    cout<<climbStairs(3);
}