#include "iostream"
#include "limits.h"
using namespace std;


long long int solve(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return (n-1)*(solve(n-1) + solve(n-2));     //(n-1)*(solution of sub problems)
                 //(solution of sub problems)  --->  if we fix {0 at ith position}  and {ith value at 0 position) ->
                                                                        //two value is fixed....rest of the solution is f(x-2)
                                                   // if we fix only {0 at ith position} and we don't know {ith values position} ->
                                                                        //one value is fixed....rest of the solution is f(x-1)
}


long long int countDerangements(int n) {
    return solve(n);
}


int main(){
    cout<<countDerangements(3);
}