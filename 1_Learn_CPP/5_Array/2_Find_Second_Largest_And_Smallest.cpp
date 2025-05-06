#include "iostream"

using namespace std;

void findSecondMinMax(int *arr,int n,int &secLargest,int &secSmallest){
    int largest = INT_MIN, smallest = INT_MAX;
    for (int i = 0; i < n; ++i) {
        //large
        if(arr[i] > largest){
            secLargest = largest;
            largest = arr[i];
        }
        else if(largest > arr[i] && arr[i] > secLargest){
            secLargest = arr[i];
        }

        //small
        if(arr[i] < smallest){
            secSmallest = smallest;
            smallest = arr[i];
        }
        else if(smallest < arr[i] && arr[i] < secSmallest){
            secSmallest = arr[i];
        }
    }
}

int main(){
    int secLargest = INT_MIN, secSmallest = INT_MAX;
    int arr[10] = {45,6,96,56,23,69,85,2,56,47};
    findSecondMinMax(arr,10,secLargest,secSmallest);
    cout<<secLargest<<" "<<secSmallest<<endl;
}