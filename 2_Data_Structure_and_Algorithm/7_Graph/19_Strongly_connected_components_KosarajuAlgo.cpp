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

void dfs(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited,int source){
    visited[source] = true;                                 //make as visited
    for (auto neighbour:adjList[source]) {               //traverse it's neighbour
        if(!visited[neighbour]){                                //if not visited
            dfs(adjList,visited,neighbour);         //call dfs for neighbour
        }
    }
}

void topologicalSort(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited,stack<int> &st,int source){
    visited[source] = true;                              //make as visited
    for (auto neighbour:adjList[source]) {               //traverse it's neighbour
        if(!visited[neighbour]){                                //if not visited
            topologicalSort(adjList,visited,st,neighbour);       //call dfs for neighbour and get topological order sort
        }
    }
    st.push(source);                         //into the stack

}

int numberOfStronglyConnectedComponentsKosarajuAlgo(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool> visited;
    stack<int> st;

    for(auto node:adjList){
        if(!visited[node.first]){
            topologicalSort(adjList,visited,st,node.first);         //get topological order into the stack
        }
    }

    unordered_map<int,list<int>> revAdjList;            //change every direction of directed graph

    for (auto node:adjList) {
        visited[node.first] = false;                    //make visited false again
        revAdjList[node.first];
        for (auto neighbour:node.second) {          //traverse neighbour
            revAdjList[neighbour].push_back(node.first);        //neighbour's adjacent is current node
        }
    }

    int numberOfComponents = 0;         //for counting components
    while (!st.empty()){                 //until stack is empty
        int topNode = st.top();             //take element from topologically sorted stack
        st.pop();

        if(!visited[topNode]){
            numberOfComponents++;                        //increasing components number
            dfs(revAdjList,visited,topNode);        //reverserDFS (dfs without stack) for transposeDirectedGraph
        }
    }
    return numberOfComponents;                   //return it

}

int main(){
    Graph g;
    g.addEdge(2,3, true);
    g.addEdge(3,0, true);
    g.addEdge(0,1, true);
    g.addEdge(1,2, true);
    g.addEdge(2,4, true);
    g.addEdge(4,5, true);
    g.addEdge(5,6, true);
    g.addEdge(6,4, true);
    g.addEdge(6,7, true);
    cout<<numberOfStronglyConnectedComponentsKosarajuAlgo(g.adjList);
}