#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


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
    vector<int> heightList;
    for (auto env:list) {
        heightList.push_back(env.second);
    }
    vector<int> choiceList;
    choiceList.push_back(heightList[0]);

    for (int i = 1; i < heightList.size(); ++i) {
        if(heightList[i] > choiceList.back()){
            choiceList.push_back(heightList[i]);
        }
        else{
            int justLessElementIndex = lower_bound(choiceList.begin(), choiceList.end(),heightList[i]) - choiceList.begin();
            choiceList[justLessElementIndex] = heightList[i];
        }
    }
    return choiceList.size();

}


int main(){
    vector<vector<int>> envelopes = {{5, 4},
                                     {6, 4},
                                     {6, 7},
                                     {2, 3}};
    cout<<maxEnvelopes(envelopes);
}