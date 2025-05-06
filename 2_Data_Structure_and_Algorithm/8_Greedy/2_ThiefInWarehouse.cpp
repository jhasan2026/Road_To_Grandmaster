#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct Item{
    string name;
    double weight;
    double value;
    Item(string name,double weight,double value){
        this->name = name;
        this->weight = weight;
        this->value = value;
    }

};

bool cmp(Item a,Item b){
    return ((double )a.value/a.weight) >( (double )b.value/b.weight);
}

void thiefInWareHouse(vector<string> itemNames, vector<int> weights,vector<int> values,vector<int> thievesCap){
    vector<Item> list;
    for (int i = 0; i < itemNames.size(); ++i) {
        list.push_back(Item(itemNames[i],(double )weights[i],(double )values[i]));
    }

    sort(list.begin(), list.end(), cmp);

    for (auto thieve:thievesCap) {
        double capacity = thieve;
        double revenue = 0;

        for (int i = 0; i < list.size(); ++i) {
            double portion = min(1.0,capacity/list[i].weight);

            if(portion == 0){
                break;
            }

            cout<<list[i].name<<" "<<portion*list[i].weight<<" kg "<<portion*list[i].value<<" taka"<<endl;
            capacity -= portion*list[i].weight;
            revenue += portion*list[i].value;
        }
        cout<<"revenue: "<<revenue<<endl<<endl;
    }

}


int main(){
    vector<string> name = {"silver-dust", "gold-dust", "salt", "sugar"};
    vector<int> values = {300, 2000, 80, 89};
    vector<int> weights = {4, 8, 10, 10};
    vector<int> thieves = {8 ,10, 6, 10};
    thiefInWareHouse(name,weights,values,thieves);

}