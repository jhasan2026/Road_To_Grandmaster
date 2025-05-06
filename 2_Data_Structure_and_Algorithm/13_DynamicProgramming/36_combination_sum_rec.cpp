#include "iostream"
#include "vector"
using namespace std;

int solve(vector<int> &num, int tar){
    if(tar < 0){            //no way to get more than target
        return 0;
    }
    if(tar == 0){           //1 way to get the target for that step
        return 1;
    }
    int findNoOfWays = 0;
    for (auto n:num) {                          //for every number of the list
        findNoOfWays += solve(num,tar - n);    //solution for -> target -= numberOfTheList
    }
    return findNoOfWays;
}
int findWays(vector<int> &num, int tar){
    return solve(num,tar);
}

int main(){
    vector<int> nums = {1,2,5};
    cout<<findWays(nums,5);
}