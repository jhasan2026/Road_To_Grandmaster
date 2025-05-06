#include "iostream"
#include "vector"
#include "list"
#include "unordered_map"
#include "stack"

using namespace std;

class Graph{
public:
    unordered_map<int,list<int>> adjList;
    vector<vector<int>> edges;

    void addEdge(int from,int to,bool direction){
        adjList[from].push_back(to);
        adjList[to];

        if(!direction){
            adjList[to].push_back(from);
        }

        vector<int> edge;
        edge.push_back(from);
        edge.push_back(to);
        edges.push_back(edge);
    }
    void printAdjList(){
        for (auto node:adjList) {
            cout<<node.first<<"--> ";
            for (auto neighbour:node.second) {
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
    }
};

void dfs(unordered_map<int,list<int>> &adjList,vector<int> &disc,vector<int> &low, unordered_map<int,bool> &visited,vector<bool> &articulationPoint,int &timer,int parent,int source){
    visited[source] = true;

    disc[source] = low[source] = timer++;

    int child = 0 ;

    for(auto neighbour: adjList[source]){
        if(neighbour == parent){
            continue;
        }

        if(!visited[neighbour]){
            dfs(adjList,disc,low,visited,articulationPoint,timer,source,neighbour);
            low[source] = min(low[source], low[neighbour]);

            if(low[neighbour] >= disc[source] && parent != -1){         //if lowestDiscoverTime of neighbour is greater than or equal discoveryTime of node  && this is not parent(starting index)
                articulationPoint[source] = true;               //this point is discovery node :: make it true
            }

            child++;                //counting child of parent(starting node)
        }
        else{
            low[source] = min(low[source], low[neighbour]);
        }
    }

    if(parent != -1 && child>1){                //if parent has more than one child :: this also a articulation point
        articulationPoint[source] = true;
    }

}


vector<bool> findingArticulationPoint(unordered_map<int,list<int>> &adjList){
    int vertex= adjList.size();
    vector<int> disc(vertex, -1);
    vector<int> low(vertex, -1);

    unordered_map<int,bool> visited;

    vector<bool> articulationPoint(vertex, false);

    int timer = 0;

    for(auto node: adjList){
        if(!visited[node.first]){
            dfs(adjList,disc,low,visited,articulationPoint,timer,-1,node.first);
        }
    }
    return articulationPoint;
}

int main(){
    Graph g;
    g.addEdge(6,7, false);
    g.addEdge(5,6, false);
    g.addEdge(8,5, false);
    g.addEdge(8,7, false);
    g.addEdge(2,5, false);
    g.addEdge(2,0, false);
    g.addEdge(0,1, false);
    g.addEdge(1,2, false);
    g.addEdge(2,3, false);
    g.addEdge(3,4, false);

    vector<bool> articulationPoint = findingArticulationPoint(g.adjList);

    for (int i = 0; i < articulationPoint.size(); ++i) {
         cout<<i<<" -> "<<articulationPoint[i]<<endl;
    }
}