#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

bool check(vector<int> base,vector<int> newBox){
    return (base[0] >= newBox[0]) && (base[1] >= newBox[1]) && (base[2] >= newBox[2]);
}

int solve(vector<vector<int>>& cuboids,int curr,int prev) {
    if(curr == cuboids.size()){
        return 0;
    }

    int include = 0;
    if(prev==-1 || check(cuboids[curr],cuboids[prev])){
        include = cuboids[curr][2] + solve(cuboids,curr+1,curr);
    }
    int exclude = 0 + solve(cuboids,curr+1,prev);
    return max(include,exclude);
}

int maxHeight(vector<vector<int>>& cuboids) {
    for (auto &eachBox:cuboids) {
        sort(eachBox.begin(), eachBox.end());
    }
    sort(cuboids.begin(), cuboids.end());
    return solve(cuboids,0,-1);
}

int main(){
    vector<vector<int>> cuboids = {{50, 45, 20},
                                   {95, 37, 53},
                                   {45, 23, 12}};
    cout<<maxHeight(cuboids);
}