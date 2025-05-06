#include "iostream"
#include "vector"
#include "unordered_set"
#include "algorithm"
using namespace std;

void removeDuplicate(vector<int> &arr){
    unordered_set<int> seen;

    auto newEnd = remove_if(arr.begin(), arr.end(),    //from arrays first to last
                            [&seen](int value){                // array element as value
        if(seen.find(value) != seen.end()){                              //check is it in the seen or not
            return true;                                                    //if found
        }
        seen.insert(value);
        return false;
    });

    arr.erase(newEnd,arr.end());
}

int main(){
    vector<int> arr = {40, 20, 10, 20, 10, 30, 50};
    removeDuplicate(arr);
    for (auto x:arr) {
        cout<<x<<" ";
    }
}