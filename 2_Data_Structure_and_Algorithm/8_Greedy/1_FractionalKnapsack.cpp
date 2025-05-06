
#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Item{
public:
    int weight;
    int value;
    Item(int weight,int value){
        this->value=value;
        this->weight=weight;
    }
};

bool cmp(Item a,Item b){
    return ((double )a.value/a.weight) >( (double )b.value/b.weight);
}

double fractionalKnapsack(vector<int> &weight,vector<int> &value,int capacity){
    vector<Item> list;
    for (int i = 0; i < weight.size(); ++i) {
        list.push_back(Item(weight[i],value[i]));
    }
    sort(list.begin(), list.end(), cmp);
    double revenue=0;
    double weightTake = (double )capacity;

    for (auto item:list) {
        double portion = min(1.0,weightTake/item.weight);
        weightTake -= portion * item.weight;
        revenue += portion * item.value;
    }
    return revenue;
}

int main() {
    vector<int> value={60,100,120};
    vector<int> weight = {10,20,30};
    cout<<fractionalKnapsack(weight,value,50);
}