#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct Product{
    string name;
    int value;
    int weight;
    Product(string name,int value,int weight){
        this->name=name;
        this->weight=weight;
        this->value=value;
    }
};

bool cpm2(Product &p1,Product &p2){
    double valPerWei1=(double )p1.value/p1.weight;
    double valPerWei2=(double )p2.value/p2.weight;
    return valPerWei1>valPerWei2;
}


int multipleKanpsack(vector<int> &weight,vector<int> &value,int capacity){
    vector<Product> list;
    for (int i = 0; i < weight.size(); ++i) {
        list.push_back(Product(to_string(i+1),value[i],weight[i]));
    }
    sort(list.begin(), list.end(),cpm2);
    vector<vector<Product>> ans;

    while (!list.empty()){
        double cap=capacity;
        double money=0;
        vector<Product> thief;
        for (auto item:list) {
            double portion=min(1.0,cap/item.weight);

            cap -= portion*item.weight;
            money +=portion*item.value;

            item.weight -=portion*item.weight;
            item.value -=portion*item.value;

            thief.push_back(Product(item.name,portion*item.value,portion*item.weight));

            if(portion==1){
                list.erase(list.begin());
            }
        }
        ans.push_back(thief);
    }

    for (auto x:ans) {
        cout<<"Thief"<<endl;
        for (auto y:x) {
            cout<<"Item "<< y.name<<" "<< y.weight <<" Kg "<<y.value<<" tk "<<endl;
        }
    }


    return ans.size();

}

int main(){
    vector<int> weight={10,15,12,8};
    vector<int> value={200,150,360,100};
    cout<<multipleKanpsack(weight,value,8)<<endl;

}