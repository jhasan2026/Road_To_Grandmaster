#include "iostream"
#include "vector"

using namespace std;

void mergeTwoArray(vector<int> &arr1,vector<int> &arr2){
    vector<int> mergeArray;
    mergeArray.reserve(arr1.size()+arr2.size());   //avoid reallocation

    mergeArray.insert(mergeArray.end(),arr1.begin(), arr1.end());
    mergeArray.insert(mergeArray.end(),arr2.begin(), arr2.end());
    for (auto x:mergeArray) {
        cout<<x<<" ";
    }
}

int main(){
    vector<int> arr1 = {40, 20, 10, 20, 10, 30, 50};
    vector<int> arr2 = {5,8,69,3,5};
    mergeTwoArray(arr1,arr2);

}