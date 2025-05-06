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

void dfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,stack<int> &st,int source){
    visited[source] = true;

    for (auto neighbour:adjList[source]) {
        if(!visited[neighbour]){
            dfs(adjList,visited,st,neighbour);
        }
    }
    st.push(source);
}


vector<int> topoSortDFS(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool> visited;
    stack<int> st;

    for (auto node:adjList) {
        if(!visited[node.first]){
            dfs(adjList,visited,st,node.first);
        }
    }

    vector<int> topoSort ;

    while (!st.empty()){
        int topNode = st.top();
        st.pop();

        topoSort.push_back(topNode);
    }
    return topoSort;

}


int main(){
    Graph g;
    g.addEdge(1,2, true);
    g.addEdge(1,3, true);
    g.addEdge(2,4, true);
    g.addEdge(2,5, true);
    g.addEdge(3,6, true);
    g.addEdge(4,7, true);
    g.addEdge(5,7, true);
    g.addEdge(6,5, true);
    g.addEdge(6,7, true);

    vector<int> topoSort = topoSortDFS(g.adjList);
    for (auto x:topoSort) {
        cout<<x<<" ";
    }

}