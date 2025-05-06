#include "iostream"
#include "vector"

using namespace std;

int solve(int n,vector<int> &arr){
    int diff1 = arr[1] - arr[0];
    int diff2 = arr[2] - arr[1];
    if(diff1 == diff2){
        for (int i = 3; i < n; ++i) {
            if(arr[i] - arr[i-1] != diff1){
                return i+1;
            }
        }
    }
    else{
        if(n == 3){
            if(arr[0]==arr[1]){
                return 3;
            }
            else if (arr[1]==arr[2]){
                return 1;
            }
            else{
                return 2;
            }
        }
        if(n == 4){
            int d2 = arr[2] - arr[1];
            int d3 = arr[3] - arr[2];
            if(d2 == d3){
                return 1;
            }
            else{
                int d = (arr[3] - arr[0])/3;
                if(arr[1] == arr[0] + d){
                    return 3;
                }
                else{
                    return 2;
                }
            }

        }
        int evidence = arr[4] - arr[3];
        if(evidence != diff1 && evidence != diff2){
            return 2;
        }
        else if(evidence != diff1 ){
            return 1;
        }
        else{
            return 3;
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<solve(n,arr);
}
