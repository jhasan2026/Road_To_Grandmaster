#include "iostream"
#include "vector"

using namespace std;

int countOccurrence(vector<int> &arr,int start,int end,int key){
    if(start==end){
        if(arr[start]==key){
            return 1;
        }
        else{
            return 0;
        }
    }
    int mid=(start+end)/2;
    int leftOccur= countOccurrence(arr,start,mid,key);
    int rightOccur= countOccurrence(arr,mid+1,end,key);
    return leftOccur+rightOccur;

}

int main(){
    vector<int> arr={2,9,5,9,9,4,9,8,9,9};
    cout<<countOccurrence(arr,0,arr.size()-1,9)<<endl;
}