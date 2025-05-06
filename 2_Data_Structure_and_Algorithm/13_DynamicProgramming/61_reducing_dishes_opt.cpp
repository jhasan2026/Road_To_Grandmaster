#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());            //sort it into ascending -> more time more satisfaction (*)
    int n = satisfaction.size();
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);

    for (int index = n-1; index >=0 ; --index) {
        for (int time = n-1; time >=0 ; --time) {
            int include = satisfaction[index]*(time+1) + next[time+1];  //if chef make the food -> time will be increase
            int exclude = 0 + next[time];     //if not -> time remain same
            curr[time] =  max(include,exclude);
        }
        next = curr;
    }
    return next[0];
}

int main(){
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout<<maxSatisfaction(satisfaction);
}