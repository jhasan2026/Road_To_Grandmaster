#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
long minCostRopes(vector<long> arr,long n){
    priority_queue<long,vector<long>,greater<long>> pq;

    for (int i = 0; i < n; ++i) {
        pq.push(arr[i]);
    }

    long cost=0;
    while (pq.size()>1){
        long first=pq.top();
        pq.pop();

        long second=pq.top();
        pq.pop();

        int mergeLenth=first+second;
        cost+=mergeLenth;
        pq.push(mergeLenth);
    }
    return cost;
}

int main(){
    vector<long> ropes={4,2,7,6,9};
    cout<<minCostRopes(ropes,5)<<endl;
}