#include "iostream"
#include "vector"
using namespace std;

int solve(int n, int x, int y, int z,vector<int> &dp){
    if(n < 0){              //if we cut more that its size
        return INT_MIN;
    }
    if(n == 0){             //if cutting is perfect -> return back with plus 0 (there will not cost after)
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    int cutRodByX =1+ solve(n-x,x,y,z,dp);           //1 for this piece and size will be (size-x)
    int cutRodByY =1+ solve(n-y,x,y,z,dp);          //1 for this piece and size will be (size-y)
    int cutRodByZ =1+ solve(n-z,x,y,z,dp);          //1 for this piece and size will be (size-z)
    return dp[n] = max(cutRodByX ,max( cutRodByY , cutRodByZ));     //max amount of pieces
}

int cutSegments(int n, int x, int y, int z) {
    vector<int> dp(n+1,-1);
    int ans = solve(n,x,y,z,dp);
    if(ans < 0){                    //it is impossible
        return 0;
    }
    return ans;
}
int main(){
    cout<<cutSegments(7,5,2,2);
}