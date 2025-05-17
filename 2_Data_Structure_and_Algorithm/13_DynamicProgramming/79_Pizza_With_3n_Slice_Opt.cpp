#include "iostream"
#include "vector"
using namespace std;


int maxSizeSlices(vector<int>& slices) {
    int n= slices.size();

    vector<int> currVec1(n/3+2,0);
    vector<int> nextVec1(n/3+2,0);
    vector<int> prevVec1(n/3+2,0);

    for (int index = n-2; index >=0 ; --index) {
        for (int noOfSlices = 1; noOfSlices <= n/3 ; ++noOfSlices) {
            int include = slices[index] + nextVec1[noOfSlices-1];
            int exclude = 0 + currVec1[noOfSlices];
            prevVec1[noOfSlices] = max(include,exclude);
        }
        nextVec1 = currVec1;
        currVec1 = prevVec1;
    }
    int firstToSecLast = currVec1[n/3];



    vector<int> currVec2(n/3+2,0);
    vector<int> nextVec2(n/3+2,0);
    vector<int> prevVec2(n/3+2,0);

    for (int index = n-1; index >=1 ; --index) {
        for (int noOfSlices = 1; noOfSlices <= n/3 ; ++noOfSlices) {
            int include = slices[index] + nextVec2[noOfSlices-1];
            int exclude = 0 + currVec2[noOfSlices];
            prevVec2[noOfSlices] = max(include,exclude);
        }
        nextVec2 = currVec2;
        currVec2 = prevVec2;
    }

    int secToLast = currVec2[n/3];
    return max(firstToSecLast,secToLast);
}

int main(){
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    cout<<maxSizeSlices(slices);
}