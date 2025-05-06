#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

long chocolateDistribution(vector<long> packet,long number,long student){
    sort(packet.begin(), packet.end());
    int i=0;
    int j=number-1;

    int mini=INT_MAX;
    while (j<packet.size()){
        int diff=packet[j] - packet[i];
        mini=min(mini,diff);
        i++;
        j--;
    }
    return mini;
}

int main(){
    vector<long> packets={3,4,1,9,56,7,9,12};
    cout<<chocolateDistribution(packets,8,5)<<endl;
}