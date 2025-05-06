#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


int coinChange(vector<int> &coins,int target){
    sort(coins.begin(), coins.end(),greater<int>());

    int ans=0;
    for (auto co:coins) {
        int noOfCoin=target/co;
        ans+= noOfCoin;
        target -= co*noOfCoin;
    }
    return ans;
}

int main(){
    vector<int> coins={10,1,25,5};
    cout<<coinChange(coins,173)<<" coins \n";

}