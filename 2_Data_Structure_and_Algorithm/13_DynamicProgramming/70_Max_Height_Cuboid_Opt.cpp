#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool checkUpLow(vector<int> &baseBox,vector<int> &upBox){
    if((baseBox[0] >= upBox[0]) &&(baseBox[1] >= upBox[1]) && (baseBox[2] >= upBox[2])){
        return true;
    }
    return false;
}

int maxHeight(vector<vector<int>>& cuboids) {
    for (auto &eachRow:cuboids) {
        sort(eachRow.begin(), eachRow.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int n= cuboids.size();

    vector<int>currVec (n+1,0);
    vector<int>nextVec (n+1,0);

    for (int currIndex = n-1; currIndex >=0 ; --currIndex) {
        for (int prevIndex = currIndex-1; prevIndex >= -1 ; --prevIndex) {
            int include = 0;
            if(prevIndex == -1 || checkUpLow(cuboids[currIndex],cuboids[prevIndex])){
                include = cuboids[currIndex][2]+ nextVec[currIndex+1];
            }
            int exclude = 0 + nextVec[prevIndex+1];
             currVec[prevIndex+1] =  max(include,exclude);
        }
        nextVec = currVec;
    }

    return nextVec[0];
}

int main(){
    vector<vector<int>> cuboids = {{50, 45, 20},
                                   {95, 37, 53},
                                   {45, 23, 12}};
    cout<<maxHeight(cuboids);
}