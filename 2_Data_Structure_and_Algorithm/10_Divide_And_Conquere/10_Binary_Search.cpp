#include "iostream"
#include "vector"

using namespace std;

int binarySearch(vector<int> arr,int start,int end,int key){
    if(start == end){
        if(key == arr[start]){
            return start;
        }
        else{
            return -1;
        }
    }
    int mid = (start+end)/2;
    if(arr[mid] == key){
        return mid;
    }
    else if(key < arr[mid]){
        return binarySearch(arr,start,mid-1,key);
    }
    else{
        return binarySearch(arr,mid+1,end,key);
    }
}

int main(){
    vector<int> arr={10,12,22,32,56,86,99,105};
    cout<<binarySearch(arr,0,arr.size()-1,22)<<endl;
    cout<<binarySearch(arr,0,arr.size()-1,85)<<endl;
}