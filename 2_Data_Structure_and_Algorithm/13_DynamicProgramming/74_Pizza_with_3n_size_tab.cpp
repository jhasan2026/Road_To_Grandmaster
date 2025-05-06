#include "iostream"
#include "vector"
using namespace std;

int maxSizeSlices(vector<int>& slices) {
    int n= slices.size();

    vector<vector<int>> dp1(n+2,vector<int>(n/3+2,0));

    for (int index = n-2; index >=0 ; --index) {
        for (int noOfSlices = 1; noOfSlices <= n/3 ; ++noOfSlices) {
            int include = slices[index] + dp1[index+2][noOfSlices-1];
            int exclude = 0 + dp1[index+1][noOfSlices];
            dp1[index][noOfSlices] = max(include,exclude);
        }
    }
    int firstToSecLast = dp1[0][n/3];

    vector<vector<int>> dp2(n+2,vector<int>(n/3+2,0));

    for (int index = n-1; index >=1 ; --index) {
        for (int noOfSlices = 1; noOfSlices <= n/3 ; ++noOfSlices) {
            int include = slices[index] + dp2[index+2][noOfSlices-1];
            int exclude = 0 + dp2[index+1][noOfSlices];
            dp2[index][noOfSlices] = max(include,exclude);
        }
    }

    int secToLast = dp2[1][n/3];
    return max(firstToSecLast,secToLast);
}
int main(){
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    cout<<maxSizeSlices(slices);
}
