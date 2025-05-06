#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
int minDaysToSurviveIsland(int surviveDays,int maxFoodEachDay,int reqFoodEachDay){
    int sunDay = surviveDays/7;
    int buyingDays = surviveDays-sunDay;

    int ans=0;
    if((buyingDays*maxFoodEachDay) % reqFoodEachDay == 0){
        ans= (buyingDays * maxFoodEachDay) / reqFoodEachDay;
    }
    else{
        ans= ((buyingDays * maxFoodEachDay) / reqFoodEachDay )+1;
    }

    if(ans <= buyingDays){
        return ans;
    }
    else{
        return -1;
    }
}

int main(){
    cout<<minDaysToSurviveIsland(10,16,2)<<endl;
}