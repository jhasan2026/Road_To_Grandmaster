#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    vector<int> curr (target+1,0);
    vector<int> prev (target+1,0);

    prev[0] = 1;
    for (int dice = 1; dice <= n; ++dice) {
        for (int tar = 1; tar <= target; ++tar) {
            int noOfWays = 0;
            for (int face = 1; face <= k; ++face) {
                if(tar-face >= 0) {
                    int temp = prev[tar-face]%MOD;
                    noOfWays += temp;
                    noOfWays = noOfWays%MOD;
                }
            }
            curr[tar] = noOfWays;
        }
        prev = curr;
    }
    return curr[target];
}

int main(){
    int n = 2, k = 6, target = 7;
    cout<<numRollsToTarget(n,k,target);
}