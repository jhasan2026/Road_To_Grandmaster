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

bool bfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,unordered_map<int,int> &parent,int source){
    visited[source] = true;     //make it as visited
    parent[source] = -1;        //source node have not any parent

    queue<int> q;
    q.push(source);     //push source in queue

    while (!q.empty()){
        int frontNode = q.front();      //take element one by one
        q.pop();

        for (auto neighbour:adjList[frontNode]) {        //traverse all neighbour(adjacent) of frontNode
            if(!visited[neighbour]){                        //if adjacent is not visited :: make it as visited and <son: adjacent, parent: frontNode>
                q.push(neighbour);              //Insert into queue
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
            else if(parent[frontNode]!=neighbour){      //{if adjacent are already visited} and {it is not parent of that adjacent}
                return true;
            }
        }
    }
    return false;

}

bool checkCycleBFS(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;      //track every node's parent
    vector<vector<int>> visitedSeq;

    for (auto node :adjList) {
        if(!visited[node.first]){
            if(bfs(adjList,visited,parent,node.first)){         //If there is a cycle :: return true
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

    if(checkCycleBFS(g.adjList)){
        cout<<"Cycle is present";
    }
    else{
        cout<<"Cycle is not present";
    }

}