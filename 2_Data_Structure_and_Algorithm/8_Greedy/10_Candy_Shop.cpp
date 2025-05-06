#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
vector<int> candyStore(vector<int> &candies,int k){
    int n=candies.size();
    sort(candies.begin(), candies.end());

    int minCost=0,maxCost=0;

    int buy=0;
    int free=n-1;

    while (buy <= free){
        minCost+=candies[buy];
        buy++;
        free-=k;
    }

    buy=n-1;
    free=0;

    while (free <= buy){
        maxCost+=candies[buy];
        buy--;
        free+=k;
    }
    vector<int> ans;
    ans.push_back(minCost);
    ans.push_back(maxCost);
    return ans;
}

int main(){
    vector<int> candies={3,2,1,4};
    vector<int> ans= candyStore(candies,2);
    for (auto x:ans) {
        cout<<x<<" ";
    }
    cout<<endl;
    break;
}