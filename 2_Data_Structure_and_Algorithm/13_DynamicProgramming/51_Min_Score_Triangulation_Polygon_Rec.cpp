#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& values,int i,int j) {
    if(i+1 == j){
        return 0;
    }
    int minScore = INT_MAX;
    for (int k = i+1; k <= j-1 ; ++k) {
        minScore = min(minScore, values[i]*values[k]*values[j] + solve(values,i,k) + solve(values,k,j));
    }
    return minScore;
}
int minScoreTriangulation(vector<int>& values) {
    return solve(values,0,values.size()-1);
}

int main(){
    vector<int> values = {1, 2, 3};
    cout<<minScoreTriangulation(values);
}