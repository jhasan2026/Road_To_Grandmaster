#include "iostream"

using namespace std;

void findMinMax(int *arr,int n,int &largest,int &smallest){
    for (int i = 0; i < n; ++i) {
        largest = max(largest,arr[i]);
        smallest = min(smallest,arr[i]);
    }
}

int main(){
    int largest = INT_MIN, smallest = INT_MAX;
    int arr[10] = {45,6,96,56,23,69,85,2,56,47};
    findMinMax(arr,10,largest,smallest);
    cout<<largest<<" "<<smallest<<endl;
}