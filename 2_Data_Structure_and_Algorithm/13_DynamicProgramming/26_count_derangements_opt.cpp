#include "iostream"
#include "limits.h"
#include "vector"
#define MOD 1000000007
using namespace std;


long long int countDerangements(int n) {


    int secondPrev = 0;
    int firstPrev = 1;

    for (int i = 3; i <= n; ++i) {
        int curr = ((n-1)*(firstPrev + secondPrev))%MOD;    //(n-1)*(solution of sub problems)
        //(solution of sub problems)  --->  if we fix {0 at ith position}  and {ith value at 0 position) ->
                                                    //two value is fixed....rest of the solution is f(x-2)
                                            // if we fix only {0 at ith position} and we don't know {ith values position} ->
                                                    //one value is fixed....rest of the solution is f(x-1)
        secondPrev = firstPrev;
        firstPrev = curr;
    }

    return firstPrev;
}


int main(){
    cout<<countDerangements(3);
}