#include "iostream"
#include "vector"
using namespace std;

int cutSegments(int n, int x, int y, int z) {
    vector<int> dp(n+1,INT_MIN);        //initially every possible cut is impossible

    dp[0] = 0;                          //if cutting is perfect -> return back with plus 0 (there will not cost after)
    for (int i = 1; i <= n; ++i) {
        int cutRodByX=INT_MIN;
        if(i-x>=0){
            cutRodByX=1+ dp[i-x];            //1 for this piece and size will be (size-x)
        }
        int cutRodByY =INT_MIN;
        if(i-y>=0){
            cutRodByY=1+ dp[i-y];           //1 for this piece and size will be (size-y)
        }
        int cutRodByZ =INT_MIN;
        if(i-z>=0){
            cutRodByZ = 1+ dp[i-z];         //1 for this piece and size will be (size-z)
        }
        dp[i] = max(cutRodByX ,max( cutRodByY , cutRodByZ));        //max amount of pieces
    }

    int ans = dp[n];
    if(ans < 0){                //it is impossible
        return 0;
    }
    return ans;
}
int main(){
    cout<<cutSegments(7,5,2,2);
}