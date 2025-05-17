#include "iostream"
#include "vector"
using namespace std;


int solve(vector<int>& slices,int index,int endIndex,int noOfSlice) {
    if(noOfSlice==0 || index > endIndex){
        return 0;
    }
    int include = slices[index] + solve(slices,index+2,endIndex,noOfSlice-1);
    int exclude = 0 + solve(slices,index+1,endIndex,noOfSlice);
    return max(include, exclude);
}
int maxSizeSlices(vector<int>& slices) {
    int n = slices.size();
    int fromFirstToSecLast = solve(slices,0,n-2,n/3);
    int fromSecondToLast = solve(slices,1,n-1,n/3);
    return max(fromFirstToSecLast,fromSecondToLast);
}

int main(){
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    cout<<maxSizeSlices(slices);
}