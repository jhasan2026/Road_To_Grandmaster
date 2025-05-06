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


bool dfs(unordered_map<int, list<int>> &adjList,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,int source){
    visited[source] = true;
    dfsVisited[source] = true;                      //if call DFS-function :: make dfsVisited as true

    for (auto neighbour:adjList[source]) {
        if(!visited[neighbour]){                                                                //if adjacent is not visited
            bool cycle =  dfs(adjList,visited, dfsVisited,neighbour);    //recursively call DFS-function  :: {node: adjacent} and {parent: node}
            if(cycle){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){                      //if the {neighbour node is visited} and {its dfsvisited[neighbour] is true}  :: cycle have
            return true;
        }
    }
    dfsVisited[source]= false;              //if the {neighbour node is visited} and {its dfsvisited[neighbour] is false}  :: make dfsVisited[source] as false(untrue)
    return false;
}
bool checkCycleDirectedDFS(unordered_map<int, list<int>> &adjList){
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    for (auto node:adjList) {
        if(!visited[node.first]){
            bool cycle= dfs(adjList,visited,dfsVisited,node.first);
            if(cycle){
                return true;
            }
        }
    }
    return false;
}


int main(){
    Graph g;
    g.addEdge(0,3, true);
    g.addEdge(3,4, true);
    g.addEdge(4,0, true);
    g.addEdge(0,2, true);
    g.addEdge(2,1, true);
    g.addEdge(1,0, true);

    cout<<checkCycleDirectedDFS(g.adjList);

}