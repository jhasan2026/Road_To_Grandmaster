#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;

int solve(int dice, int k, int target) {
    if(target < 0){
        return 0;
    }
    if(dice==0 && target!=0){
        return 0;
    }
    if(target==0 && dice!=0){             //there is not 0 type face
        return 0;
    }
    if(dice==0 && target==0){            //one way :: nothing to do
        return 1;
    }

    int ans = 0;
    for (int face = 1; face <= k; ++face) {
        int temp = solve(dice-1,k,target-face);
        ans = ans + (temp%MOD);
    }
    return ans%MOD;
}
int numRollsToTarget(int n, int k, int target) {
    return solve(n,k,target);
}


int main(){
    int n = 2, k = 6, target = 7;
    cout<<numRollsToTarget(n,k,target);
}