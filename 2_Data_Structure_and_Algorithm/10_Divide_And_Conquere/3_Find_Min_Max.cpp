#include "iostream"
#include "vector"
using namespace std;

void findMinMax(vector<int> &arr,int start,int end,int &smallest,int &largest){
    if(start == end){                        // if there is only one element
        smallest = min(smallest,arr[start]);     //check is it smaller than the smallest
        largest = max(largest,arr[start]);      // larger
        return;
    }

    int mid = (start + end)/2;
    findMinMax(arr,start,mid,smallest,largest);        //find from the left sub array
    findMinMax(arr,mid+1,end,smallest,largest);      // find from right
}

int main(){
    int smallest=INT_MAX,largest=INT_MIN;
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
    findMinMax(arr,0,arr.size()-1,smallest,largest);
    cout<<smallest<<" "<<largest<<endl;
}