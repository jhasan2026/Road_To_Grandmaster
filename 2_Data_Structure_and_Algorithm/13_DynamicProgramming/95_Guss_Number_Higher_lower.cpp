#include "iostream"
#include "vector"

using namespace std;

int solve(int start,int end) {
    if(start >= end){
        return 0;
    }
    int ans = INT_MAX;
    for (int i = start; i <= end; ++i) {
        ans = min(ans , i + max(solve(start,i-1), solve(i+1,end)));
    }
    return ans;
}
int getMoneyAmount(int n) {
    return solve(1,n);
}

int main(){
    cout<<getMoneyAmount(10);
}