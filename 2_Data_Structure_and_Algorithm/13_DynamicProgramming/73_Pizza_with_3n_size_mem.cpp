#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& slices,int index,int endIndex,int noOfSlices,vector<vector<int>> &dp) {
    if(noOfSlices==0 || index>endIndex){
        return 0;
    }

    if(dp[index][noOfSlices] != -1){
        return dp[index][noOfSlices];
    }

    int include = slices[index] + solve(slices,index+2,endIndex,noOfSlices-1,dp);
    int exclude = 0 + solve(slices,index+1,endIndex,noOfSlices,dp);
    return dp[index][noOfSlices] = max(include,exclude);
}
int maxSizeSlices(vector<int>& slices) {
    int n= slices.size();

    vector<vector<int>> dp1(n+1,vector<int>(n/3+1,-1));
    int firstToSecLast = solve(slices,0,n-2,n/3,dp1);

    vector<vector<int>> dp2(n+1,vector<int>(n/3+1,-1));
    int secToLast = solve(slices,1,n-1,n/3,dp2);
    return max(firstToSecLast,secToLast);
}
int main(){
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    cout<<maxSizeSlices(slices);
}
