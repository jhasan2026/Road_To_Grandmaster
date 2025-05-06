#include "iostream"
#include "vector"
#include "list"
#include "unordered_map"
#include "queue"

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

bool dfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,int source,int parent){

    visited[source] = true;             //make source node as visited

    for (auto neighbour:adjList[source]) {          //traverse all adjacent of source node
        if(!visited[neighbour]){                        //if adjacent is not visited
            bool checkCycle = dfs(adjList,visited,neighbour,source);        //recursively call DFS-function  :: {node: adjacent} and {parent: node}

            if(checkCycle){
                return true;
            }
        }
        else if(neighbour != parent){           //if adjacent is visited and is not child of parent  :: cycle has
            return true;
        }
    }
    return false;               //not found any cycle
}

bool checkCycleDFS(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool> visited;

    for (auto node :adjList) {      //node is:: i and parent of source node is:: -1
        if(!visited[node.first]){

            if(dfs(adjList,visited,node.first,-1)){     //if there is a cycle :: return true
                return true;
            }
        }
    }
    return false;

}

int main(){
    Graph g;
    g.addEdge(0,1, false);
    g.addEdge(0,2, false);
    g.addEdge(0,7, false);
    g.addEdge(1,4, false);
    g.addEdge(2,3, false);
    g.addEdge(2,4, false);
    g.addEdge(3,5, false);
    g.addEdge(3,6, false);
    g.addEdge(6,7, false);

    if(checkCycleDFS(g.adjList)){
        cout<<"Cycle is present";
    }
    else{
        cout<<"Cycle is not present";
    }


}