#include "iostream"

using namespace std;

int linearSearch(int *arr,int n,int key){
    for (int i = 0; i < n; ++i) {
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n=6;
    int arr[6] = {45 ,96 ,86 ,78 ,6,89};
    int ans= linearSearch(arr,n,88);
    if(ans == -1){
        cout<<"Not found";
    }
    else{
        cout<<ans;
    }
}