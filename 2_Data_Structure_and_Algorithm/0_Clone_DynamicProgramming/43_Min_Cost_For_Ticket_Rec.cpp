#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int>& days,int noOfDays, vector<int>& costs,int index) {
    if(index >= days.size()){
        return 0;
    }
    int oneDayCost = costs[0] + solve(days,noOfDays,costs,index+1);
    int i = 0;
    for (i= index; (i < noOfDays) && (days[i] < days[index] + 7) ; ++i);
    int sevenDayCost = costs[1] + solve(days,noOfDays,costs,i);

    for (i= index; (i < noOfDays) && (days[i] < days[index] + 30) ; ++i);
    int thirtyDayCost = costs[2] + solve(days,noOfDays,costs,i);
    return min(oneDayCost, min(sevenDayCost,thirtyDayCost));
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    return solve(days,days.size(),costs,0);
}


int main(){
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout<<mincostTickets(days,costs);
}