#include "iostream"
#include "vector"
#define MOD 1000000007
using namespace std;


long long int countDerangements(int n) {
   long long secPrev = 0;
    long long firstPrev = 1;

    for (int i = 3; i <= n; ++i) {
        long long curr = ((i-1)%MOD)*(firstPrev%MOD  + secPrev%MOD)%MOD;
        secPrev = firstPrev;
        firstPrev = curr;
    }

    return firstPrev;
}


int main(){
    cout<<countDerangements(4);
}