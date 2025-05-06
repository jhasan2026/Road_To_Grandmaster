#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
bool comparator(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
}
vector<pair<int,int>> maxMeetingInRoom(vector<int> &startTime,vector<int> &finishTime){
    vector<pair<int,int>> time;
    for (int i = 0; i < startTime.size(); ++i) {
        time.push_back(make_pair(startTime[i],finishTime[i]));
    }
    sort(time.begin(), time.end(), comparator);
    vector<pair<int,int>> ans;
    ans.push_back(time[0]);
    int endTime=time[0].second;
    for (int i = 1; i < time.size(); ++i) {
        if(time[i].first > endTime){
            ans.push_back(time[i]);
            endTime= time[i].second;
        }
    }
    return ans;

}

int main(){
    vector<int> start={5,3,6,3,1,8,8,12,2,0,5};
    vector<int> end={7,5,10,8,4,12,11,14,13,6,9};
    vector<pair<int,int>> ans= maxMeetingInRoom(start,end);
    for (auto x:ans) {
        cout<<x.first<<"--"<<x.second<<endl;
    }
    break;
}