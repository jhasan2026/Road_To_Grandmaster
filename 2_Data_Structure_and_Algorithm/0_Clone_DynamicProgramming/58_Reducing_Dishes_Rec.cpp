#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int solve(vector<int>& satisfaction,int index,int time) {
    if(index >= satisfaction.size()){
        return 0;
    }
    int include = (satisfaction[index] * (time+1)) + solve(satisfaction,index+1,time+1);
    int exclude = 0 + solve(satisfaction,index+1,time);
    return max(include, exclude);
}
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction,0,0);
}

int main(){
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout<<maxSatisfaction(satisfaction);
}