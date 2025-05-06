#include "iostream"
#include "vector"

using namespace std;

void findAllSubSetsSolve(vector<int> arr,int index,vector<int> subSet,vector<vector<int>> &ans){
    if(index >= arr.size()){
        ans.push_back(subSet);
        return;
    }

    //exclude
    findAllSubSetsSolve(arr,index+1,subSet,ans);

    // include
    int element = arr[index];
    subSet.push_back(element);
    findAllSubSetsSolve(arr,index+1,subSet,ans);

}

vector<vector<int>> findAllSubSets(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> subSet;
    findAllSubSetsSolve(arr,0,subSet,ans);
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> subsets = findAllSubSets(arr);

    for (auto x:subsets) {
        for (auto y:x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}