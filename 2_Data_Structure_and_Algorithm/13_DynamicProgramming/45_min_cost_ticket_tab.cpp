#include "iostream"
#include "vector"
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int noOfDays = days.size();
    vector<int> dp(noOfDays+1,0);



    for (int index = noOfDays-1; index >=0 ; --index) {
        int oneDayPass = costs[0] + dp[index+1];             //oneDayPass -> jump to next day

        int i=0;
        for (i = index; (i < noOfDays) && (days[i] < days[index] +7 ); ++i,dp);     //check if (the day is less than noOfDays) and (that day number is less than (entry day + 7)) --> i++
        int sevenDayPass = costs[1] + dp[i];                                            //cost for 7day pass and rest of the calculation starts at ith day

        for (i = index; (i < noOfDays) && (days[i] < days[index] +30 ); ++i);       //check if (the day is less than noOfDays) and (that day number is less than (entry day + 30)) --> i++
        int thirtyDayPass = costs[2] + dp[i];                                           //cost for 30day pass and rest of the calculation starts at ith day

        dp[index] =  min(oneDayPass,min(sevenDayPass,thirtyDayPass));           // min among them
    }


    return dp[0];
}

int main(){
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    cout<<mincostTickets(days,costs);
}