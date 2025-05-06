#include "iostream"
#include "vector"
using namespace std;

int findWays(vector<int> &num, int tar){
    vector<int> dp(tar +1 , 0);         //no way to get more than target

    dp[0] = 1;                  //1 way to get the target for that step

    for (int t = 1; t <= tar; ++t) {
        int findNoOfWays = 0;
        for (auto n:num) {                  //for every number of the list
            if(t-n >= 0) {
                findNoOfWays += dp[t - n];          //solution for -> target -= numberOfTheList
            }
        }
        dp[t] = findNoOfWays;
    }

    return dp[tar];
}

int main(){
    vector<int> nums = {1,2,5};
    cout<<findWays(nums,5);
}