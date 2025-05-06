#include "iostream"
#include "vector"
#include "list"
#include "unordered_map"
#include "set"

using namespace std;

class WeiGraph{
public:
    unordered_map<int,list<pair<int,int>>> adjList;
    vector<vector<int>> edges;

    void addEdge(int from,int to,int weight,bool direction){
        adjList[from].push_back({to,weight});
        adjList[to];

        if(!direction){
            adjList[to].push_back({from,weight});
        }

        vector<int> edge;
        edge.push_back(from);
        edge.push_back(to);
        edge.push_back(weight);
        edges.push_back(edge);
    }
    void printAdjList(){
        for (auto node:adjList) {
            cout<<node.first<<"--> ";
            for (auto neighbour:node.second) {
                cout<<"["<<neighbour.first<<","<<neighbour.second<<"] ";
            }
            cout<<endl;
        }
    }
};

unordered_map<int,int> shortestPathDijkstraAlgoSingleSrc(unordered_map<int,list<pair<int,int>>> adjList,int src){
    unordered_map<int,int> distance ;                           //distance calculate vector from (source node)

    for (auto node:adjList) {
        distance[node.first] = INT_MAX;                     //make vector full of infinity(INT_MAX) value
    }

    distance[src] = 0;                              //distance to source is zero

    set<pair<int,int>> setOfPair;                   //create a set of pair<distance From Source, value of node>
    setOfPair.insert({0,src});          //distance:: source to source is 0  ,value:: source

    while (!setOfPair.empty()){                         //until setOfPair(sop) is empty
        auto topNode = *(setOfPair.begin());    //get pair with minimum distance from source in
        setOfPair.erase(setOfPair.begin());

        int topNodeDistance = topNode.first;        //pair's distance
        int topNodeValue = topNode.second;          //pair's node value

        for (auto neighbour:adjList[topNodeValue]) {                    //tarverse it's adjacent
            if(topNodeDistance + neighbour.second < distance[neighbour.first]){         //if sum of[distance of topNode(as parent)] and [weight of neighbour] is less than [distance of neighbour]

                auto prevRecordIndex = setOfPair.find({distance[neighbour.first],neighbour.first});  //if a copy of neighbour is already exist in the setOfPair :: catch in the record

                if(prevRecordIndex != setOfPair.end()){                         //if record exist
                    setOfPair.erase(prevRecordIndex);                   //remove from the setOfPair
                }

                distance[neighbour.first] = topNodeDistance + neighbour.second;         //update neighbour's distance with sum of it's minimum value
                setOfPair.insert({distance[neighbour.first],neighbour.first});           //insert into the setOfPair with updated distance value
            }
        }
    }
    return distance;

}


int main(){
    WeiGraph g;
    g.addEdge(2,1,3, false);
    g.addEdge(2,0,1, false);
    g.addEdge(0,1,7, false);
    g.addEdge(1,4,1, false);
    g.addEdge(1,3,5, false);
    g.addEdge(0,3,2, false);
    g.addEdge(3,4,7, false);

    unordered_map<int,int> ans = shortestPathDijkstraAlgoSingleSrc(g.adjList,0);

    for (auto node:ans) {
        cout<<node.first<<" --> "<<node.second<<endl;
    }
}