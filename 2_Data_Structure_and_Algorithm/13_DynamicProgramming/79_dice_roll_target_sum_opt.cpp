#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    vector<long long> curr(target+1,0);
    vector<long long> prev(target+1,0);
    prev[0] = 1;
    for (int dice = 1; dice <= n; ++dice) {
        for (int tar = 1; tar <= target; ++tar) {
            long long ans = 0;
            for (int face = 1; face <= k; ++face) {
                if(tar-face >= 0) {
                    ans = ans + (prev[tar - face]) % MOD;
                }
            }
            curr[tar] = ans%MOD;
        }
        prev = curr;
    }
    return curr[target]%MOD;
}

int main(){
    int n = 30, k = 30, target = 500;
    cout<<numRollsToTarget(n,k,target);
}

