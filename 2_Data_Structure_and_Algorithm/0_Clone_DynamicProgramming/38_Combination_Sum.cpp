#include "iostream"
#include "vector"
using namespace std;

void solve(vector<int>& candidates, int target,int index,int total,vector<int> &temp,vector<vector<int>> &combinations) {
    if(target < total){
        return;
    }
    if(index >= candidates.size()){
        return;
    }
    if(target == total){
        combinations.push_back(temp);
        return;
    }
    temp.push_back(candidates[index]);
    solve(candidates,target,index,total + candidates[index],temp,combinations);
    temp.pop_back();
    solve(candidates,target,index+1,total,temp,combinations);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> combinations;
    vector<int> temp;
    solve(candidates,target,0,0,temp,combinations);
    return combinations;
}

int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> total = combinationSum(candidates, target);

    for (int i = 0; i < total.size(); ++i) {
        for (int j = 0; j < total[i].size(); ++j) {
            cout<<total[i][j]<<" ";
        }
        cout<<endl;
    }
}