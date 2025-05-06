#include "iostream"
#include "math.h"
using namespace std;

void perfectCubeRootRange(int range){
    int cubeRoot = cbrt(range);
    for (int i = 1; i <= cubeRoot; ++i) {
        cout<<i<<" "<<pow(i,3)<<endl;
    }
}

int main(){
    perfectCubeRootRange(1000);
}