#include "iostream"
#include "vector"
using namespace std;

int climbStairs(int n) {

    int secPrev = 1;
    int firstPrev = 1;
    for (int i = 2; i <= n; ++i) {
        int oneStairJump = firstPrev;
        int twoStairJump = secPrev;
        int curr = oneStairJump + twoStairJump;
        secPrev = firstPrev;
        firstPrev = curr;
    }
    return firstPrev;
}


int main(){
    cout<<climbStairs(3);
}