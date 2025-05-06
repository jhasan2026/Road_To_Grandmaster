#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


bool cmp5(pair<int,int> &event1,pair<int,int> &event2){
    return event1.second<event2.second;
}

int peopleNeedActivity(vector<int> &start,vector<int> &end){
    vector<pair<int,int>> workList;
    for (int i = 0; i < start.size(); ++i) {
        workList.push_back({start[i],end[i]});
    }
    sort(workList.begin(), workList.end(),cmp5);

    vector<vector<pair<int,int>>> ans;
    while (!workList.empty()){
        vector<pair<int,int>> people;
        people.push_back(workList[0]);
        int endtime=workList[0].second;
        workList.erase(workList.begin());
        vector<pair<int,int>>::iterator it;
        for (it=workList.begin();it<=workList.end();it++){
            if(people.size()>=3){
                break;
            }
            if(it->first>=endtime){
                endtime=it->second;
                people.push_back(*it);
                workList.erase(it);
            }
        }
        ans.push_back(people);
    }

    for (auto x:ans) {
        cout<<"people:"<<endl;
        for (auto y:x) {
            cout<<y.first<<" "<<y.second<<endl;
        }
    }
    cout<<endl;
    return ans.size();
}

int main(){
    vector<int> start={11,2,9,2,1,3,1,4,10};
    vector<int> end={13,4,15,10,3,7,5,8,14};
    cout<<peopleNeedActivity(start,end)<<endl;

}