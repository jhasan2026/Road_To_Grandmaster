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

void dfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &component,int source){
    component.push_back(source);            //push base in the component
    visited[source] = true;

    for (auto neighbour:adjList[source]) {
        if(!visited[neighbour]){
            dfs(adjList,visited,component,neighbour);
        }
    }
}

vector<vector<int>> DFS(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool> visited;
    vector<vector<int>> visitedSeq;
    for (auto node :adjList) {
        if(!visited[node.first]){
            vector<int> component;                      //every node works as a component
            dfs(adjList,visited,component,node.first);      //call dfs for it
            visitedSeq.push_back(component);            //return visited sequence
        }
    }
    return visitedSeq;

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

    vector<vector<int>> ans = DFS(g.adjList);

    for (auto x :ans) {
        for (auto y:x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }

}