#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

int solve(int n,int *arr){
    int count[5]={0};
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    int noOfTaxi = 0;
    noOfTaxi += count[4];
    noOfTaxi += count[3];
    if(count[3] >= count[1]){
        noOfTaxi += ceil((float)count[2]/2);
    }
    else{
        if(count[2] % 2 ==0){
            noOfTaxi += count[2]/2;
            count[1] -= count[3];
            noOfTaxi += ceil((float )count[1]/4);

        }
        else{
            noOfTaxi += ceil((float)count[2]/2);
            if(count[1] - count[3] > 2){
                count[1] -= count[3];
                count[1] -= 2;
                noOfTaxi += ceil((float )count[1]/4);
            }
        }
    }
    return noOfTaxi;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<solve(n,arr);
}
