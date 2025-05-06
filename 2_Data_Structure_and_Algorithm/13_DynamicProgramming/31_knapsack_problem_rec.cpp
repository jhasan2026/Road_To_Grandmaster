#include "iostream"
#include "vector"

using namespace std;

int solve(vector<int> weight, vector<int> value, int maxWeight,int index)
{
    if(index == 0){                             //for the last element
        if(weight[0] <= maxWeight){          //if the weight is under capacity take it
            return value[0];                    //add its values
        }
        else{
            return 0;
        }
    }
    int include = 0;
    if(weight[index] <= maxWeight){                                                 //if the weight is under capacity take it
        include = value[index] + solve(weight,value,maxWeight-weight[index],index-1);   //capacity -= weightOfTheProduct
    }

    int exclude = 0 + solve(weight,value,maxWeight,index-1);                //skip the element
    return max(include,exclude);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight,value,maxWeight,n-1);       //from n-1 ...... 0th element
}

int main(){
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    cout<<knapsack(weight,value,4,5);

}