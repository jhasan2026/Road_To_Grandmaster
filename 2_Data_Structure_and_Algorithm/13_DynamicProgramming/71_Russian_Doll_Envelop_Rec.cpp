#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool cmp(const pair<int,int> &env1,const pair<int,int> &env2){
    if(env1.first == env2.first){
        return env1.second > env2.second;
    }
    return env1.first < env2.first;
}

int solve(vector<pair<int,int>> list,int currIndex,int prevIndex) {
    if(currIndex >= list.size()){
        return 0;
    }
    int include = 0;
    if(prevIndex==-1 || list[currIndex].second > list[prevIndex].second){
        include = 1 + solve(list,currIndex+1,currIndex);
    }
    int exclude = 0 + solve(list,currIndex+1,prevIndex);
    return max(include,exclude);
}


int maxEnvelopes(vector<vector<int>>& envelopes) {
    vector<pair<int,int>> list;
    for (int i = 0; i < envelopes.size(); ++i) {
        list.push_back({envelopes[i][0], envelopes[i][1]});
    }
    sort(list.begin(), list.end(), [](const pair<int, int>& env1, const pair<int, int>& env2) {
        if (env1.first == env2.first) {
            return env1.second > env2.second;
        }
        return env1.first < env2.first;
    });

    return solve(list,0,-1);
}


int main(){
    vector<vector<int>> envelopes = {{5, 4},
                                     {6, 4},
                                     {6, 7},
                                     {2, 3}};
    cout<<maxEnvelopes(envelopes);
}