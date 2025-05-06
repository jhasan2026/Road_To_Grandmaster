#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool cmp3(pair<int,int> &p1,pair<int,int> &p2){
    return p1.second<p2.second;
}

int activitySelection(vector<int> &start,vector<int> &end){
    vector<pair<int,int>> time;
    for (int i = 0; i < start.size(); ++i) {
        time.push_back({start[i],end[i]});
    }
    sort(time.begin(), time.end(),cmp3);

    int endTime=time[0].second;
    vector<pair<int,int>> done;
    done.push_back(time[0]);
    for (int i = 1; i < time.size(); ++i) {
        if(time[i].first >= endTime){
            endTime=time[i].second;
            done.push_back(time[i]);
        }
    }

    for (auto x:done) {
        cout<<x.first<<" --> "<<x.second<<endl;
    }
    cout<<endl;

    return done.size();
}

int main(){
    vector<int> start={5,3,6,3,1,8,8,12,2,0,5};
    vector<int> end={7,5,10,8,4,12,11,14,13,6,9};
    cout<<activitySelection(start,end)<<endl;

}