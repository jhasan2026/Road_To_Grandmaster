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

        if(!direction){                     //if undirected to--from
            adjList[to].push_back(from);
        }

        vector<int> edge;
        edge.push_back(from);
        edge.push_back(to);
        edges.push_back(edge);
    }
    void printAdjList(){
        for (auto node:adjList) {
            cout<<node.first<<"--> ";                   //iterate :: maps first element
            for (auto neighbour:node.second) {       //iterate corresponding to first element's set
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
    }
};

void bfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &component,int source){
    visited[source] = true;             //make it is visited
    component.push_back(source);
    queue<int> q;
    q.push(source);             //push base in the queue

    while (!q.empty()){
        int frontNode = q.front();          //take element from queue
        q.pop();

        for (auto neighbour:adjList[frontNode]) {       //take its neighbour elements
            if(!visited[neighbour]){                    //if its not visited :: push it into
                q.push(neighbour);
                visited[neighbour] = true;              //make it as visited
                component.push_back(neighbour);         //push it as a visited
            }
        }
    }

}

vector<vector<int>> BFS(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool> visited;
    vector<vector<int>> visitedSeq;
    for (auto node :adjList) {          //iterate all node as a base one by one (for
        if(!visited[node.first]){                        //if base is not visited :: call bfs
            vector<int> component;
            bfs(adjList,visited,component,node.first);
            visitedSeq.push_back(component);
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

    vector<vector<int>> ans = BFS(g.adjList);

    for (auto x :ans) {
        for (auto y:x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }

}