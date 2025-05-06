#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct Env{
public:
    int width;
    int height;
    Env(int width,int height){
        this->width=width;
        this->height=height;
    }
};

bool cmp(Env &ev1,Env &ev2){
    if(ev1.width == ev2.width){
        return ev1.height > ev2.height;
    }
    return ev1.width < ev2.width;
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    vector<Env> list;
    for (auto ev:envelopes) {
        Env obj(ev[0],ev[1]);
        list.push_back(obj);
    }
    sort(list.begin(), list.end(), cmp);

    vector<int> heightList;
    for (auto ev:list) {
        heightList.push_back(ev.height);
    }

    vector<int> choiceList;
    choiceList.push_back(heightList[0]);

    for (int i = 1; i < heightList.size(); ++i) {
        if(heightList[i] > choiceList.back()){
            choiceList.push_back(heightList[i]);
        }
        else{
            int justImiGreaterValueIdx = lower_bound(choiceList.begin(), choiceList.end(),heightList[i]) - choiceList.begin();
            choiceList[justImiGreaterValueIdx] = heightList[i];
        }
    }
    return choiceList.size();
}

int main(){
    vector<vector<int>> envelopes = {{5, 4},
                                     {6, 4},
                                     {6, 7},
                                     {2, 3}};
    cout<<maxEnvelopes(envelopes)
}